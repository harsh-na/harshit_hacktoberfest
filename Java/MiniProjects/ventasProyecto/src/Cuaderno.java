public class Cuaderno extends Producto {
    private String name = "Cuaderno";

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
