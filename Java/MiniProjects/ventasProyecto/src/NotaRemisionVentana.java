import javax.swing.*;
import javax.swing.text.MaskFormatter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Vector;

public class NotaRemisionVentana extends JFrame implements ActionListener {
    private ArrayList<Producto> productos;
    private ProductoVentana nuevoProducto;
    private JLabel titulo;
    private String notaRemision = "";

    private JButton agregar;
    private JButton borrar;
    private JButton modificar;
    private JButton imprimir;
    private JButton salir;

    private JPanel totales;
    private JLabel subtotal;
    private JLabel totalIva;
    private JLabel costoTotal;
    private JLabel prorrateo;
    private double subtotalNum = 0;
    private double totalNum = 0;
    private double ivaNum = 0;

    private JPanel datos;
    private JLabel tituloPanel;
    private MaskFormatter mascara1;
    private MaskFormatter mascara2;
    private MaskFormatter mascara3;
    private JLabel numeroNotaLabel;
    private JTextField numeroNota;
    private JLabel nombreCompradorLabel;
    private JTextField nombreComprador;
    private JLabel direccionLabel;
    private JTextField direccion;
    private JLabel telefonoLabel;
    private JFormattedTextField telefono;
    private JLabel rfcText;
    private JFormattedTextField rfc;
    private JLabel fechaNotaLabel;
    private JFormattedTextField fechaNota;
    private JLabel opcionPagoLabel;
    private JLabel pagoMesesText;
    private JRadioButton contado;
    private JRadioButton credito;
    private ButtonGroup tipoPago;
    private Integer[] numeroMeses;
    private JComboBox<Integer> mesesCredito;
    private boolean pagoDeContado;
    private JTable tabla;
    private String[] nombresColumnas;
    private ModeloTabla modeloTabla;
    private JScrollPane scrollPane;

    public NotaRemisionVentana() {
        productos = new ArrayList<>();

        titulo = new JLabel("Nota remisión");
        titulo.setFont(new Font("Arial", Font.BOLD, 40));
        titulo.setBounds(250, 10, 300, 60);

        datos = new JPanel();
        datos.setBorder(BorderFactory.createLineBorder(Color.GRAY, 3));
        datos.setLayout(null);
        datos.setBounds(50, 75, 685, 170);

        tituloPanel = new JLabel("Información.");
        tituloPanel.setFont(new Font("Arial", Font.BOLD, 25));
        tituloPanel.setBounds(70, 62, 150, 30);
        tituloPanel.setOpaque(true);

        numeroNota = new JTextField();
        numeroNotaLabel = new JLabel("Número nota: ");
        numeroNotaLabel.setBounds(10, 30, 150, 20);
        numeroNotaLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        numeroNota.setText(String.valueOf((int)((Math.random()*300) + 1)));
        numeroNota.setEditable(false);
        numeroNota.setFont(new Font("Arial", Font.PLAIN, 20));
        numeroNota.setBounds(160, 28, 50, 30);
        datos.add(numeroNotaLabel);
        datos.add(numeroNota);

        fechaNotaLabel = new JLabel("Fecha de nota: ");
        fechaNotaLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        fechaNotaLabel.setBounds(340, 30, 150, 20);
        try {
            mascara1 = new MaskFormatter("##/##/####");
            fechaNota = new JFormattedTextField(mascara1);
            fechaNota.setFocusLostBehavior(JFormattedTextField.COMMIT);
            fechaNota.setBounds(500, 28, 70, 30);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        datos.add(fechaNotaLabel);
        datos.add(fechaNota);

        nombreCompradorLabel = new JLabel("Nombre cliente: ");
        nombreCompradorLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        nombreCompradorLabel.setBounds(10, 65, 150, 20);
        nombreComprador = new JTextField();
        nombreComprador.setBounds(160, 60, 170, 30);
        datos.add(nombreCompradorLabel);
        datos.add(nombreComprador);

        direccionLabel = new JLabel("Direccion cliente: ");
        direccionLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        direccionLabel.setBounds(340, 60, 170, 30);
        direccion = new JTextField();
        direccion.setBounds(500, 60, 150, 30);
        datos.add(direccionLabel);
        datos.add(direccion);

        telefonoLabel = new JLabel("Telefono: ");
        telefonoLabel.setBounds(340, 93, 170, 30);
        telefonoLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        try {
            mascara2 = new MaskFormatter("##########");
            telefono = new JFormattedTextField(mascara2);
            telefono.setFocusLostBehavior(JFormattedTextField.COMMIT);
            telefono.setBounds(500, 92, 80, 30);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        datos.add(telefonoLabel);
        datos.add(telefono);

        rfcText = new JLabel("RFC cliente: ");
        rfcText.setFont(new Font("Arial", Font.PLAIN, 20));
        rfcText.setBounds(10, 92, 170, 30);
        try {
            mascara3 = new MaskFormatter("UUUU########***");
            rfc = new JFormattedTextField(mascara3);
            rfc.setFocusLostBehavior(JFormattedTextField.COMMIT);
            rfc.setBounds(160, 92, 140,30);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        datos.add(rfcText);
        datos.add(rfc);

        opcionPagoLabel = new JLabel("Forma de pago: ");
        opcionPagoLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        opcionPagoLabel.setBounds(10, 130, 170, 30);
        datos.add(opcionPagoLabel);

        contado = new JRadioButton("Contado");
        contado.addActionListener(this);
        contado.setBounds(160, 137, 100, 20);
        contado.setFont(new Font("Arial", Font.PLAIN, 18));
        contado.setFocusable(false);
        datos.add(contado);

        credito = new JRadioButton("Credito");
        credito.addActionListener(this);
        credito.setBounds(260, 137, 100, 20);
        credito.setFont(new Font("Arial", Font.PLAIN, 20));
        credito.setFocusable(false);
        datos.add(credito);

        pagoMesesText = new JLabel("Meses: ");
        pagoMesesText.setFont(new Font("Arial", Font.PLAIN, 18));
        pagoMesesText.setBounds(360, 137, 70, 20);
        pagoMesesText.setVisible(false);
        datos.add(pagoMesesText);

        numeroMeses = new Integer[] {2, 3, 5, 7, 12, 24};
        mesesCredito = new JComboBox<>(numeroMeses);
        mesesCredito.addActionListener(this);
        mesesCredito.setBounds(430, 135, 50, 25);
        mesesCredito.setFont(new Font("Arial", Font.PLAIN, 18));
        mesesCredito.setFocusable(false);
        mesesCredito.setVisible(false);
        datos.add(mesesCredito);

        pagoDeContado = true;
        contado.doClick();

        tipoPago = new ButtonGroup();
        tipoPago.add(contado);
        tipoPago.add(credito);

        scrollPane = new JScrollPane();
        scrollPane.setBorder(BorderFactory.createLineBorder(Color.GRAY, 3));
        scrollPane.setBounds(50, 250, 685, 100);

        nombresColumnas = new String[] {"Clave", "Descripcion", "Cantidad", "Unidad", "Precio Unitario", "Importe"};

        modeloTabla = new ModeloTabla(null, nombresColumnas);

        tabla = new JTable(modeloTabla);

        scrollPane.setViewportView(tabla);

        totales = new JPanel();
        totales.setBorder(BorderFactory.createLineBorder(Color.GRAY, 3));
        totales.setLayout(null);
        totales.setBounds(50, 355, 225, 50);

        subtotal = new JLabel("Subtotal: 0");
        subtotal.setFont(new Font("Arial", Font.BOLD, 15));
        subtotal.setBounds(8, 10, 150, 15);
        totales.add(subtotal);

        totalIva = new JLabel("Iva: 0");
        totalIva.setFont(new Font("Arial", Font.BOLD, 15));
        totalIva.setBounds(8, 30, 80, 15);
        totales.add(totalIva);

        costoTotal = new JLabel("Total: 0");
        costoTotal.setFont(new Font("Arial", Font.BOLD, 15));
        costoTotal.setBounds(126, 10, 150, 15);
        totales.add(costoTotal);

        prorrateo = new JLabel("Prorrateo: 0");
        prorrateo.setVisible(false);
        prorrateo.setFont(new Font("Arial", Font.BOLD, 15));
        prorrateo.setBounds(90, 30, 100, 15);
        totales.add(prorrateo);

        agregar = new JButton("Agregar");
        agregar.addActionListener(this);
        agregar.setFocusable(false);
        agregar.setBounds(554, 375, 90, 30);

        borrar = new JButton("Borrar");
        borrar.addActionListener(this);
        borrar.setFocusable(false);
        borrar.setBounds(463, 375, 90,30);

        modificar = new JButton("Modificar");
        modificar.addActionListener(this);
        modificar.setFocusable(false);
        modificar.setBounds(645, 375, 90, 30);

        imprimir = new JButton("Imprimir");
        imprimir.addActionListener(this);
        imprimir.setFocusable(false);
        imprimir.setBounds(372, 375, 90, 30);

        salir = new JButton("Salir");
        salir.addActionListener(this);
        salir.setFocusable(false);
        salir.setBounds(281, 375, 90, 30);

        this.add(titulo);
        this.add(tituloPanel);
        this.add(datos);
        this.add(scrollPane);
        this.add(totales);
        this.add(agregar);
        this.add(borrar);
        this.add(modificar);
        this.add(imprimir);
        this.add(salir);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(350, 100, 800, 460);
        this.setLayout(null);
        this.setResizable(false);
        this.setVisible(true);
    }

    private void agregarNuevoProducto() {
        nuevoProducto = new ProductoVentana(this, true);
        UtilEscolar util = (UtilEscolar) nuevoProducto.getProducto();
        if (nuevoProducto.isJdialogCerrado() || util == null) {
            return;
        }
        if (buscarProducto(util.getClave()) == null) {
            Vector<Object> nuevaFila = new Vector<>();
            nuevaFila.add(util.getClave());
            nuevaFila.add(util.getDescripcion());
            nuevaFila.add(util.getCantidad());
            nuevaFila.add(util.getUnidadMedida());
            nuevaFila.add(util.getPrecioUnitario());
            nuevaFila.add(util.getImporte());
            modeloTabla.addRow(nuevaFila);
            productos.add((Producto) util);
            actualizarPago((int) mesesCredito.getSelectedItem(), util.getImporte(), productos.size());
        } else {
            JOptionPane.showMessageDialog(null, "El producto ya existe en la lista!", "Error.", JOptionPane.WARNING_MESSAGE);
        }
    }

    private Producto buscarProducto(int producto) {
        if (productos.isEmpty()) {
            return null;
        }
        for (Producto product : productos) {
            if (product.getClave() == producto) {
                return product;
            }
        }
        return null;
    }

    private void removerProducto() {
        if (tabla.getSelectedRow() != -1) {
            for (int i = 0; i < productos.size(); i++) {
                if (productos.get(i).getClave() == (int) tabla.getValueAt(tabla.getSelectedRow(), 0)) {
                    actualizarPago((int) mesesCredito.getSelectedItem(), -((UtilEscolar) productos.get(i)).getImporte(), productos.size()-1);
                    productos.remove(i);
                }
            }
            modeloTabla.removeRow(tabla.getSelectedRow());
        } else {
            JOptionPane.showMessageDialog(null, "No se selecciono ningun elemento!", "Error", JOptionPane.WARNING_MESSAGE);
        }
    }

    public void modificarProducto() {
        if (tabla.getSelectedRow() != -1 && productos.size() > tabla.getSelectedRow()) {
            nuevoProducto = new ProductoVentana(this, true, (UtilEscolar) buscarProducto((Integer) modeloTabla.getValueAt(tabla.getSelectedRow(), 0)), (new UtilEscolar()).utiles);
            UtilEscolar producto = (UtilEscolar) nuevoProducto.getProducto();
            if (producto != null) {
                modeloTabla.setValueAt(producto.getClave(), tabla.getSelectedRow(), 0);
                modeloTabla.setValueAt(producto.getDescripcion(), tabla.getSelectedRow(), 1);
                modeloTabla.setValueAt(producto.getCantidad(), tabla.getSelectedRow(), 2);
                modeloTabla.setValueAt(producto.getUnidadMedida(), tabla.getSelectedRow(), 3);
                modeloTabla.setValueAt(producto.getPrecioUnitario(), tabla.getSelectedRow(), 4);
                modeloTabla.setValueAt(producto.getImporte(), tabla.getSelectedRow(), 5);
                for (int i = 0; i < productos.size(); i++) {
                    if (productos.get(i).getClave() == producto.getClave()) {
                        actualizarPago((int) mesesCredito.getSelectedItem(), -((UtilEscolar) productos.get(i)).getImporte(), productos.size());
                        actualizarPago((int) mesesCredito.getSelectedItem(), producto.getImporte(), productos.size());
                        productos.set(i, producto);
                    }
                }
            }
            tabla.clearSelection();
        } else {
            JOptionPane.showMessageDialog(null, "No se selecciono ningun elemento!", "Error", JOptionPane.WARNING_MESSAGE);
        }
    }

    private void actualizarPago(int meses, double precioProducto, int cantidadProductos) {
        if (cantidadProductos != 0) {
            subtotalNum += precioProducto;
            ivaNum = subtotalNum * .16;
            totalNum = subtotalNum + ivaNum;
            subtotal.setText(String.format("Subtotal: %.2f", subtotalNum));
            totalIva.setText(String.format("Iva: %.2f", ivaNum));
            if (pagoDeContado) {
                costoTotal.setText(String.format("Total: %.2f", totalNum));
            } else {
                costoTotal.setText(String.format("Total: %.2f", totalNum/meses));
            }
        } else {
            subtotalNum = ivaNum = totalNum = 0;
            subtotal.setText(String.format("Subtotal: %.2f", subtotalNum));
            totalIva.setText(String.format("Iva: %.2f", ivaNum));
            costoTotal.setText(String.format("Total: %.2f", totalNum));
        }
    }

    private void imprimirNotaRemision(int numElementos) {
        notaRemision = "";
        if (numElementos != 0 && checarDatosUsurio()) {
            notaRemision += "\tNota Remision:\n";
            notaRemision += "Numero nota: " + numeroNota.getText() + "\n";
            notaRemision += "Fecha nota: " + fechaNota.getText() + "\n";
            notaRemision += "Nombre cliente: " + nombreComprador.getText() + "\n";
            notaRemision += "RFC: " + rfc.getText() + "\n";
            notaRemision += "Direccin cliente: " + direccion.getText() + "\n";
            notaRemision += "Telefono: " + telefono.getText() + "\n\n";
            for (int i = 0; i < productos.size(); i++) {
                notaRemision += "Producto " + String.valueOf(i+1) + ": \n";
                notaRemision += productos.get(i);
                notaRemision += "\n";
            }
            notaRemision += "Subtotal: " + String.format("%.2f", subtotalNum) + "\n";
            notaRemision += "Iva: " + String.format("%.2f", ivaNum) + "\n";
            if (!pagoDeContado) {
                notaRemision += "Meses: " + String.valueOf((int) mesesCredito.getSelectedItem()) + "\n";
                notaRemision +="Total: " + String.format("%.2f", totalNum/((int) mesesCredito.getSelectedItem())) + "\n";
            } else {
                notaRemision +="Total: " + String.format("%.2f", totalNum) + "\n";
            }
            VentanaImpresionProducto ventana = new VentanaImpresionProducto(notaRemision, false, this);
        } else {
            JOptionPane.showMessageDialog(null, "Error, datos faltantes!", "Error", JOptionPane.WARNING_MESSAGE);
        }
    }

    private boolean checarDatosUsurio() {
        if (telefono.getText().trim().length() < 10 || fechaNota.getText().trim().length() < 10 ||  rfc.getText().trim().length() < 15) {
            return false;
        }
        return true;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == agregar) {
            agregarNuevoProducto();
        } else if (e.getSource() == borrar) {
            removerProducto();
        } else if (e.getSource() == modificar) {
            modificarProducto();
        } else if (e.getSource() == salir) {
            System.exit(0);
        } else if (e.getSource() == imprimir) {
            imprimirNotaRemision(productos.size());
        } else if (e.getSource() == contado) {
            if (!pagoDeContado) {
                pagoDeContado = true;
                pagoMesesText.setVisible(false);
                mesesCredito.setVisible(false);
                prorrateo.setVisible(false);
                actualizarPago(0, 0, productos.size());
            }
        } else if (e.getSource() == credito) {
            if (pagoDeContado) {
                pagoDeContado = false;
                mesesCredito.setVisible(true);
                pagoMesesText.setVisible(true);
                prorrateo.setVisible(true);
                mesesCredito.setSelectedIndex(0);
            }
        } else if (e.getSource() == mesesCredito) {
            if (!pagoDeContado) {
                prorrateo.setText("Prorrateo: " + mesesCredito.getSelectedItem());
                actualizarPago((int) mesesCredito.getSelectedItem(), 0, productos.size());
            }
        }
    }
}
