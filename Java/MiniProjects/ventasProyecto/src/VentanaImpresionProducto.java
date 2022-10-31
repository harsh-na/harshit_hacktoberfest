import javax.swing.*;

public class VentanaImpresionProducto extends JDialog {
    JTextArea text;

    public VentanaImpresionProducto(String notaRemision, boolean modal, NotaRemisionVentana padre) {
        super(padre, modal);

        text = new JTextArea();
        text.setText(notaRemision);
        text.setEditable(false);

        this.add(text);
        this.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
        this.setVisible(true);
        this.setResizable(false);
        this.pack();
    }
}
