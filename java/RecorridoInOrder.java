import java.util.ArrayList;
import java.util.List;

public class RecorridoInOrder {

    // Método auxiliar recursivo para realizar
    // el recorrido In-Order del árbol
    public static void inOrderAux(Nodo nodo, List<Integer> resultado) {

        // Caso base:
        // Si el nodo es null, finaliza la recursividad
        if (nodo == null) {
            return;
        }

        // 1. Recorremos el subárbol izquierdo
        inOrderAux(nodo.izquierdo, resultado);

        // 2. Visitamos la raíz
        // Agregamos el valor del nodo a la lista resultado
        resultado.add(nodo.valor);

        // 3. Recorremos el subárbol derecho
        inOrderAux(nodo.derecho, resultado);
    }

    // Método principal que inicia el recorrido In-Order
    public static List<Integer> recorridoInOrder(Nodo raiz) {

        // Lista donde se almacenará el recorrido
        List<Integer> resultado = new ArrayList<>();

        // Llamada al método auxiliar recursivo
        inOrderAux(raiz, resultado);

        // Retornamos la lista con el recorrido completo
        return resultado;
    }

    public static void main(String[] args) {

        // Construcción manual del árbol
        //
        // 4
        // / \
        // 2 6
        // / \ / \
        // 1 3 5 7

        Nodo raiz = new Nodo(4);

        raiz.izquierdo = new Nodo(2);
        raiz.derecho = new Nodo(6);

        raiz.izquierdo.izquierdo = new Nodo(1);
        raiz.izquierdo.derecho = new Nodo(3);

        raiz.derecho.izquierdo = new Nodo(5);
        raiz.derecho.derecho = new Nodo(7);

        // Prueba del algoritmo
        System.out.println("--- Prueba Ejercicio 4 ---");

        System.out.println("Resultado esperado: [1, 2, 3, 4, 5, 6, 7]");

        // Mostramos el resultado obtenido
        System.out.println("Tu resultado:       "
                + recorridoInOrder(raiz));
    }
}