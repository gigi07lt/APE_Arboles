public class Ejercicio3_Binario2 {

    // Método recursivo para calcular la altura de un árbol binario
    public static int calcularAltura(Nodo raiz) {

        // Caso base:
        // Si el nodo es null, significa que el árbol está vacío
        // y su altura es 0
        if (raiz == null) {
            return 0;
        }

        // Se calcula la altura del subárbol izquierdo
        int alturaIzquierda = calcularAltura(raiz.izquierdo);

        // Se calcula la altura del subárbol derecho
        int alturaDerecha = calcularAltura(raiz.derecho);

        // Se retorna la mayor altura encontrada + 1
        // (+1 representa el nodo actual)
        return Math.max(alturaIzquierda, alturaDerecha) + 1;
    }

    public static void main(String[] args) {

        // Construcción manual del árbol
        //
        // 1
        // \
        // 2
        // /
        // 3

        Nodo raiz = new Nodo(1);

        raiz.derecho = new Nodo(2);
        raiz.derecho.izquierdo = new Nodo(3);

        // Prueba del algoritmo
        System.out.println("--- Prueba Ejercicio 3 ---");

        System.out.println("Altura esperada: 3");

        // Cálculo de la altura del árbol
        System.out.println("Altura calculada: "
                + calcularAltura(raiz));

        // Prueba con árbol vacío (null)
        System.out.println("Altura de árbol nulo (esperado 0): "
                + calcularAltura(null));
    }
}
