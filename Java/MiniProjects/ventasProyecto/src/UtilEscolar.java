import java.util.ArrayList;

public class UtilEscolar extends Producto {
    private int cantidad;
    private double precioUnitario;
    private String unidadMedida;
    private double importe;

    public ArrayList<Producto> utiles;

    public UtilEscolar() {
        utiles = new ArrayList<>();
        utiles.add(new Lapiz());
        utiles.add(new Pluma());
        utiles.add(new Sacapuntas());
        utiles.add(new Lapicera());
        utiles.add(new Cuaderno());
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
        actualizarImporte();
    }

    public double getPrecioUnitario() {
        return precioUnitario;
    }

    public void setPrecioUnitario(double precioUnitario) {
        this.precioUnitario = precioUnitario;
        actualizarImporte();
    }

    public void setUnidadMedida(String medida) {
        this.unidadMedida = medida;
    }

    public String getUnidadMedida() {
        return this.unidadMedida;
    }

    public double getImporte() {
        return importe;
    }

    public void setImporte(double importe) {
        this.importe = importe;
    }

    private void actualizarImporte(){
        this.importe = this.cantidad * this.precioUnitario;
    }

    protected String obtenerNombre() {
        return obtenerDescripcion();
    }


    @Override
    public String obtenerDescripcion() {
        return null;
    }

    @Override
    public String obtenerClave() {
        return null;
    }

    @Override
    public String ImprimirProducto() {
        String productoString = "";
        productoString += "Clave: " + String.valueOf(getClave()) + ", ";
        productoString += "Descripcion: " + getDescripcion() + ", ";
        productoString += "Cantidad: " + String.valueOf(cantidad) + "\n";
        productoString += "Precio Unitario: " + String.format("%.2f", precioUnitario) + ", ";
        productoString += "Unidad Medida: " + unidadMedida + ", ";
        productoString += "Importe: " + String.format("%.2f", importe) + ". \n";
        return productoString;
    }

    @Override
    public String toString() {
        return ImprimirProducto();
    }
}
