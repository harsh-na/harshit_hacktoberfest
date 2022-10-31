import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.LinkedList;

public class ProductoVentana extends JDialog implements ActionListener, ChangeListener {
    private UtilEscolar producto;
    private JLabel titulo;
    private LinkedList<JLabel> pedirDatos;
    private double[] preciosUnitarios;
    private String[] descripciones;
    private String[] unidadesDeMedida;
    private JComboBox<String> clavesArticulos;
    private JComboBox<String> unidadMedida;
    private JTextField descripcionText;
    private JTextField precioUnitarioText;
    private JTextField importeText;
    private JSpinner cantidad;
    private JButton botonAceptar;
    private JButton botonCancelar;
    private boolean jdialogCerrado;

    public ProductoVentana(NotaRemisionVentana padre, boolean modal) {
        this(padre, modal, null, (new UtilEscolar()).utiles);
    }

    public ProductoVentana(NotaRemisionVentana padre, boolean modal, UtilEscolar producto, ArrayList<Producto> utiles) {
        super(padre, modal);
        jdialogCerrado = true;

        this.producto = new UtilEscolar();

        titulo = new JLabel("Producto.");
        titulo.setBounds(93, 10, 300, 40);
        titulo.setFont(new Font("Arial", Font.PLAIN, 35));
        pedirDatos = new LinkedList<>();
        pedirDatos.add(new JLabel("Clave articulo:"));
        pedirDatos.get(0).setBounds(10, 60, 150, 30);
        pedirDatos.get(0).setFont(new Font("Arial", Font.PLAIN, 16));
        pedirDatos.add(new JLabel("Descripcion: "));
        pedirDatos.get(1).setBounds(10, 100, 150, 30);
        pedirDatos.get(1).setFont(new Font("Arial", Font.PLAIN, 16));
        pedirDatos.add(new JLabel("Cantidad: "));
        pedirDatos.get(2).setBounds(10, 140, 150, 30);
        pedirDatos.get(2).setFont(new Font("Arial", Font.PLAIN, 16));
        pedirDatos.add(new JLabel("Precio unitario:"));
        pedirDatos.get(3).setBounds(10, 180, 150, 30);
        pedirDatos.get(3).setFont(new Font("Arial", Font.PLAIN, 16));
        pedirDatos.add(new JLabel("Unidad de medida:"));
        pedirDatos.get(4).setBounds(10, 220, 150, 30);
        pedirDatos.get(4).setFont(new Font("Arial", Font.PLAIN, 16));
        pedirDatos.add(new JLabel("Importe: "));
        pedirDatos.get(5).setBounds(10, 260, 150, 30);
        pedirDatos.get(5).setFont(new Font("Arial", Font.PLAIN, 16));

        String[] articulos = {"Articulo 1", "Articulo 2", "Articulo 3", "Articulo 4", "Articulo 5"};
        clavesArticulos = new JComboBox<>(articulos);
        clavesArticulos.setSelectedIndex(0);
        clavesArticulos.addActionListener(this);
        clavesArticulos.setBounds(150, 60, 150, 30);
        clavesArticulos.setFocusable(false);

        descripciones = new String[]{
                utiles.get(0).obtenerDescripcion(),
                utiles.get(1).obtenerDescripcion(),
                utiles.get(2).obtenerDescripcion(),
                utiles.get(3).obtenerDescripcion(),
                utiles.get(4).obtenerDescripcion()};
        descripcionText = new JTextField();
        descripcionText.setBounds(150, 100, 150, 30);
        descripcionText.setEditable(false);
        descripcionText.setFont(new Font("Arial", Font.PLAIN, 16));
        descripcionText.setText(descripciones[0]);

        cantidad = new JSpinner(new SpinnerNumberModel(1, 1, 50, 1));
        cantidad.setBounds(150, 140, 150, 30);
        cantidad.addChangeListener(this);
        cantidad.setFont(new Font("Arial", Font.PLAIN, 16));
        cantidad.setEditor(new JSpinner.DefaultEditor(cantidad));
        cantidad.setFocusable(false);
        ((JSpinner.DefaultEditor) cantidad.getEditor()).getTextField().setEditable(false);

        preciosUnitarios = new double[] {5.5, 16.9, 10.5, 3.3, 9.2};
        precioUnitarioText = new JTextField();
        precioUnitarioText.setText(String.valueOf(preciosUnitarios[0]));
        precioUnitarioText.setBounds(150, 180, 150, 30);
        precioUnitarioText.setFont(new Font("Arial", Font.PLAIN, 16));
        precioUnitarioText.setEditable(false);

        unidadesDeMedida = new String[] {"Unitario", "Kilogramo"};
        unidadMedida = new JComboBox<>(unidadesDeMedida);
        unidadMedida.setSelectedIndex(0);
        unidadMedida.setEditable(false);
        unidadMedida.setFont(new Font("Arial", Font.PLAIN, 16));
        unidadMedida.setBounds(150, 220, 150, 30);
        unidadMedida.setFocusable(false);
        unidadMedida.addActionListener(this);

        importeText = new JTextField();
        importeText.setEditable(false);
        importeText.setBounds(150, 260, 150, 30);
        importeText.setFont(new Font("Arial", Font.PLAIN, 16));
        importeText.setText(String.valueOf(preciosUnitarios[0]*1));

        botonAceptar = new JButton("Aceptar");
        botonAceptar.setBounds(50, 300, 80, 30);
        botonAceptar.addActionListener(this);

        botonCancelar = new JButton("Cancelar");
        botonCancelar.setBounds(170, 300, 100,30);
        botonCancelar.addActionListener(this);

        if (producto == null) {
            this.producto.setClave(1);
            this.producto.setDescripcion(descripciones[0]);
            this.producto.setCantidad(1);
            this.producto.setPrecioUnitario(5.5);
            this.producto.setImporte(5.5);
            this.producto.setUnidadMedida((String) unidadMedida.getSelectedItem());
        } else {
            clavesArticulos.setSelectedIndex(producto.getClave()-1);
            clavesArticulos.setEnabled(false);
            this.producto.setClave(producto.getClave());
            this.producto.setCantidad(producto.getCantidad());
            this.producto.setUnidadMedida(producto.getUnidadMedida());
            this.producto.setPrecioUnitario(producto.getPrecioUnitario());
            descripcionText.setText(this.producto.getDescripcion());
            cantidad.setValue(this.producto.getCantidad());
            precioUnitarioText.setText(String.valueOf(this.producto.getPrecioUnitario()));
            importeText.setText(String.valueOf(this.producto.getImporte()));
            if (this.producto.getUnidadMedida().equals(unidadesDeMedida[0])) {
                unidadMedida.setSelectedIndex(0);
            } else {
                unidadMedida.setSelectedIndex(1);
            }
        }

        this.add(titulo);
        this.add(pedirDatos.get(0));
        this.add(pedirDatos.get(1));
        this.add(pedirDatos.get(2));
        this.add(pedirDatos.get(3));
        this.add(pedirDatos.get(4));
        this.add(pedirDatos.get(5));
        this.add(clavesArticulos);
        this.add(descripcionText);
        this.add(cantidad);
        this.add(precioUnitarioText);
        this.add(unidadMedida);
        this.add(importeText);
        this.add(botonAceptar);
        this.add(botonCancelar);
        this.setResizable(false);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setLayout(null);
        this.setBounds(700,225,350,400);
        this.setVisible(true);
    }

    public Producto getProducto() {
        return this.producto;
    }

    public boolean isJdialogCerrado() {
        return jdialogCerrado;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botonAceptar) {
            jdialogCerrado = false;
            dispose();
        } else if (e.getSource() == botonCancelar) {
            producto = null;
            jdialogCerrado = false;
            dispose();
        } else if (e.getSource() == clavesArticulos) {
            unidadMedida.setSelectedIndex(0);
            producto.setClave(clavesArticulos.getSelectedIndex()+1);
            producto.setDescripcion(descripciones[clavesArticulos.getSelectedIndex()]);
            producto.setCantidad(1);
            producto.setPrecioUnitario(preciosUnitarios[clavesArticulos.getSelectedIndex()]);
            producto.setUnidadMedida((String) unidadMedida.getSelectedItem());
            descripcionText.setText(producto.getDescripcion());
            cantidad.setValue(producto.getCantidad());
            precioUnitarioText.setText(String.valueOf(producto.getPrecioUnitario()));
            importeText.setText(String.format("%.2f", producto.getImporte()));
        } else if (e.getSource() == unidadMedida) {
            producto.setUnidadMedida((String) unidadMedida.getSelectedItem());
        }
    }

    @Override
    public void stateChanged(ChangeEvent e) {
        if (e.getSource() == cantidad) {
            producto.setCantidad((int) cantidad.getValue());
            importeText.setText(String.format("%.2f", producto.getImporte()));
        }
    }
}
