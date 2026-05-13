#include <iostream>
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

// Función recursiva para insertar valores en un
// Árbol Binario de Búsqueda (BST)
Nodo* insertar(Nodo* raiz, int valor) {

    // Caso base:
    // Si el nodo actual es nulo,
    // se crea un nuevo nodo con el valor recibido
    if (raiz == nullptr) {
        return new Nodo(valor);
    }

    // Si el valor es menor que el nodo actual,
    // se inserta en el subárbol izquierdo
    if (valor < raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    }

    // Si el valor es mayor,
    // se inserta en el subárbol derecho
    else if (valor > raiz->valor) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }

    // Se retorna la raíz actualizada
    return raiz;
}

int main() {

    // Creación de la raíz del árbol
    Nodo* raiz = new Nodo(10);

    // Inserción de valores en el BST
    insertar(raiz, 5);
    insertar(raiz, 15);
    insertar(raiz, 3);

    // Prueba del algoritmo
    cout << "--- Prueba Ejercicio 2 ---" << endl;

    cout << "Raiz (Esperado 10): "
         << raiz->valor << endl;

    // Verificamos el hijo izquierdo
    if(raiz->izquierdo)
        cout << "Hijo Izquierdo (Esperado 5): "
             << raiz->izquierdo->valor << endl;
    else
        cout << "Hijo Izquierdo: null" << endl;

    // Verificamos el hijo derecho
    if(raiz->derecho)
        cout << "Hijo Derecho (Esperado 15): "
             << raiz->derecho->valor << endl;
    else
        cout << "Hijo Derecho: null" << endl;

    // Verificamos el hijo izquierdo del nodo 5
    if(raiz->izquierdo && raiz->izquierdo->izquierdo)
        cout << "Hijo Izq del 5 (Esperado 3): "
             << raiz->izquierdo->izquierdo->valor << endl;
    else
        cout << "Hijo Izq del 5: null" << endl;

    return 0;
}