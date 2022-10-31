public class Pluma extends Producto {
    private String name = "Pluma";

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
