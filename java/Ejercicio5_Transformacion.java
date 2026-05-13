public class Ejercicio5_Transformacion {

    // Método recursivo para invertir un árbol binario
    // (crear su árbol espejo)
    public static Nodo invertir(Nodo raiz) {

        // Caso base:
        // Si el nodo es null, no existe nada que invertir
        if (raiz == null) {
            return null;
        }

        // Intercambiamos el hijo izquierdo con el derecho
        Nodo temp = raiz.izquierdo;
        raiz.izquierdo = raiz.derecho;
        raiz.derecho = temp;

        // Aplicamos recursividad a los subárboles
        invertir(raiz.izquierdo);
        invertir(raiz.derecho);

        // Retornamos la raíz del árbol invertido
        return raiz;
    }

    public static void main(String[] args) {

        // Construcción manual del árbol
        //
        // 1 1
        // / \ --> / \
        // 2 3 3 2

        Nodo raiz = new Nodo(1);

        raiz.izquierdo = new Nodo(2);
        raiz.derecho = new Nodo(3);

        // Estado inicial del árbol
        System.out.println("--- Prueba Ejercicio 5 ---");

        System.out.println("Antes de invertir:");

        System.out.println("Hijo Izq: "
                + raiz.izquierdo.valor
                + " | Hijo Der: "
                + raiz.derecho.valor);

        // Llamada al método para invertir el árbol
        invertir(raiz);

        // Resultado después de invertir el árbol
        System.out.println("\nDespués de invertir (Esperado: Izq 3 | Der 2):");

        // Verificación del nuevo hijo izquierdo
        String izq = (raiz.izquierdo != null)
                ? String.valueOf(raiz.izquierdo.valor)
                : "null";

        // Verificación del nuevo hijo derecho
        String der = (raiz.derecho != null)
                ? String.valueOf(raiz.derecho.valor)
                : "null";

        System.out.println("Hijo Izq: " + izq + " | Hijo Der: " + der);
    }
}