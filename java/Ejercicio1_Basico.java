import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// Clase que representa un nodo de un árbol N-ario
class NodoN {

    // Valor almacenado en el nodo
    public int valor;

    // Lista de hijos del nodo
    public List<NodoN> hijos;

    // Constructor para crear un nodo sin hijos
    public NodoN(int valor) {
        this.valor = valor;
        this.hijos = new ArrayList<>();
    }

    // Constructor para crear un nodo con hijos definidos
    public NodoN(int valor, List<NodoN> hijos) {
        this.valor = valor;
        this.hijos = hijos;
    }
}

public class Ejercicio1_Basico {

    // Método recursivo para contar todos los nodos del árbol
    public static int contarNodos(NodoN raiz) {

        // Caso base:
        // Si el nodo es null, significa que no existe
        // y no aporta nodos al conteo
        if (raiz == null) {
            return 0;
        }

        // Se comienza contando el nodo actual
        int total = 1;

        // Se recorren todos los hijos del nodo actual
        // y se suman sus nodos recursivamente
        for (NodoN hijo : raiz.hijos) {
            total += contarNodos(hijo);
        }

        // Se retorna el total acumulado
        return total;
    }

    public static void main(String[] args) {

        // Construcción manual del árbol:
        //
        // 1
        // / | \
        // 2 3 4
        // / \
        // 5 6

        // Nodos hoja
        NodoN n5 = new NodoN(5);
        NodoN n6 = new NodoN(6);

        // Nodo 2 con hijos 5 y 6
        NodoN n2 = new NodoN(2, Arrays.asList(n5, n6));

        // Otros hijos de la raíz
        NodoN n3 = new NodoN(3);
        NodoN n4 = new NodoN(4);

        // Nodo raíz
        NodoN raiz = new NodoN(1, Arrays.asList(n2, n3, n4));

        // Prueba del algoritmo
        System.out.println("--- Prueba Ejercicio 1 ---");

        System.out.println("Nodos esperados: 6");

        // Se llama al método para contar los nodos
        System.out.println("Nodos calculados: " + contarNodos(raiz));
    }
}