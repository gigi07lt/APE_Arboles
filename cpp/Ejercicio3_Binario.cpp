#include <iostream>
#include <algorithm> // Biblioteca necesaria para utilizar std::max
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

// Función recursiva para calcular la altura del árbol
int calcularAltura(Nodo* raiz) {

    // Caso base:
    // Si el nodo es nulo, la altura es 0
    if (raiz == nullptr) {
        return 0;
    }

    // Se calcula la altura del subárbol izquierdo
    int alturaIzquierda = calcularAltura(raiz->izquierdo);

    // Se calcula la altura del subárbol derecho
    int alturaDerecha = calcularAltura(raiz->derecho);

    // Se retorna la mayor altura encontrada + 1
    // (+1 representa el nodo actual)
    return max(alturaIzquierda, alturaDerecha) + 1;
}

int main() {

    // Construcción manual del árbol
    //
    //        1
    //         \
    //          2
    //         /
    //        3

    Nodo* raiz = new Nodo(1);

    raiz->derecho = new Nodo(2);
    raiz->derecho->izquierdo = new Nodo(3);

    // Prueba del algoritmo
    cout << "--- Prueba Ejercicio 3 ---" << endl;

    cout << "Altura esperada: 3" << endl;

    // Cálculo de altura del árbol
    cout << "Altura calculada: "
         << calcularAltura(raiz) << endl;

    // Prueba con árbol vacío (nullptr)
    cout << "Altura de arbol nulo (esperado 0): "
         << calcularAltura(nullptr) << endl;

    return 0;
}