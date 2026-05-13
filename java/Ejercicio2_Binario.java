// Clase que representa un nodo de un árbol binario
class Nodo {

    // Valor almacenado en el nodo
    int valor;

    // Referencias a los hijos izquierdo y derecho
    Nodo izquierdo, derecho;

    // Constructor del nodo
    Nodo(int valor) {
        this.valor = valor;
    }
}

public class Ejercicio2_Binario {

    // Método recursivo para insertar nodos en un
    // Árbol Binario de Búsqueda (BST)
    public static Nodo insertar(Nodo raiz, int valor) {

        // Caso base:
        // Si el nodo es null, se crea un nuevo nodo
        if (raiz == null) {
            return new Nodo(valor);
        }

        // Si el valor es menor que el nodo actual,
        // se inserta en el subárbol izquierdo
        if (valor < raiz.valor) {
            raiz.izquierdo = insertar(raiz.izquierdo, valor);
        }

        // Si el valor es mayor o igual,
        // se inserta en el subárbol derecho
        else {
            raiz.derecho = insertar(raiz.derecho, valor);
        }

        // Retornamos la raíz actualizada
        return raiz;
    }

    public static void main(String[] args) {

        // Creación de la raíz del árbol
        Nodo raiz = new Nodo(10);

        // Inserción de valores en el BST
        insertar(raiz, 5);
        insertar(raiz, 15);
        insertar(raiz, 3);

        // Prueba del algoritmo
        System.out.println("--- Prueba Ejercicio 2 ---");

        System.out.println("Raiz (Esperado 10): " + raiz.valor);

        // Verificación del hijo izquierdo de la raíz
        String izq = (raiz.izquierdo != null)
                ? String.valueOf(raiz.izquierdo.valor)
                : "null";

        System.out.println("Hijo Izquierdo de Raiz (Esperado 5): " + izq);

        // Verificación del hijo derecho de la raíz
        String der = (raiz.derecho != null)
                ? String.valueOf(raiz.derecho.valor)
                : "null";

        System.out.println("Hijo Derecho de Raiz (Esperado 15): " + der);

        // Verificación del hijo izquierdo del nodo 5
        String izqIzq = (raiz.izquierdo != null &&
                raiz.izquierdo.izquierdo != null)
                        ? String.valueOf(raiz.izquierdo.izquierdo.valor)
                        : "null";

        System.out.println("Hijo Izquierdo del 5 (Esperado 3): " + izqIzq);
    }
}