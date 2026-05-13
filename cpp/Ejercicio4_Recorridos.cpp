#include <iostream>
#include <vector>
using namespace std;

// Estructura de un nodo para un árbol binario
struct Nodo {

    // Valor almacenado en el nodo
    int valor;

    // Punteros a los hijos izquierdo y derecho
    Nodo* izquierdo;
    Nodo* derecho;

    // Constructor del nodo
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Función auxiliar recursiva para realizar
// el recorrido In-Order del árbol
void inOrderAux(Nodo* nodo, vector<int>& resultado) {

    // Caso base:
    // Si el nodo es nulo, termina la recursividad
    if (nodo == nullptr) {
        return;
    }

    // 1. Recorremos el subárbol izquierdo
    inOrderAux(nodo->izquierdo, resultado);

    // 2. Visitamos la raíz
    // Guardamos el valor del nodo en el vector
    resultado.push_back(nodo->valor);

    // 3. Recorremos el subárbol derecho
    inOrderAux(nodo->derecho, resultado);
}

// Función principal que inicia el recorrido In-Order
vector<int> recorridoInOrder(Nodo* raiz) {

    // Vector donde se almacenará el resultado
    vector<int> resultado;

    // Llamada a la función recursiva auxiliar
    inOrderAux(raiz, resultado);

    // Retornamos el recorrido completo
    return resultado;
}

int main() {

    // Construcción manual del árbol
    //
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7

    Nodo* raiz = new Nodo(4);

    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(6);

    raiz->izquierdo->izquierdo = new Nodo(1);
    raiz->izquierdo->derecho = new Nodo(3);

    raiz->derecho->izquierdo = new Nodo(5);
    raiz->derecho->derecho = new Nodo(7);

    // Se ejecuta el recorrido In-Order
    vector<int> res = recorridoInOrder(raiz);

    // Prueba del algoritmo
    cout << "--- Prueba Ejercicio 4 ---" << endl;

    cout << "Resultado esperado: 1 2 3 4 5 6 7 " << endl;

    cout << "Tu resultado:       ";

    // Mostramos el contenido del vector resultado
    for(int val : res) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}