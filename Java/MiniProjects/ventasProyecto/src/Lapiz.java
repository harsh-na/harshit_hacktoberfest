public class Lapiz extends Producto {
    private String name = "Lapiz";

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
