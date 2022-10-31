public class Sacapuntas extends Producto {
    private String name = "Sacapuntas";


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
