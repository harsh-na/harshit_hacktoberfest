public class Lapicera extends Producto {
    private String name = "Lapicera";

    @Override
    public String obtenerDescripcion() {
        return name;
    }

    @Override
    public String obtenerClave() {
        return null;
    }

    @Override
    public String ImprimirProducto() {
        return null;
    }
}
