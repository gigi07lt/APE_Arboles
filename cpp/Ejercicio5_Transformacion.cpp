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

// Función recursiva para invertir un árbol binario
// (crear su árbol espejo)
Nodo* invertir(Nodo* raiz) {

    // Caso base:
    // Si el nodo es nulo, no hay nada que invertir
    if (raiz == nullptr) {
        return nullptr;
    }

    // Intercambiamos el hijo izquierdo con el derecho
    Nodo* temp = raiz->izquierdo;
    raiz->izquierdo = raiz->derecho;
    raiz->derecho = temp;

    // Aplicamos recursividad sobre ambos subárboles
    invertir(raiz->izquierdo);
    invertir(raiz->derecho);

    // Retornamos la raíz del árbol invertido
    return raiz;
}

int main() {

    // Construcción manual del árbol
    //
    //        1
    //      /   \
    //     2     3
    //
    // Después de invertir:
    //
    //        1
    //      /   \
    //     3     2

    Nodo* raiz = new Nodo(1);

    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);

    // Estado inicial del árbol
    cout << "--- Prueba Ejercicio 5 ---" << endl;

    cout << "Antes de invertir:" << endl;

    cout << "Hijo Izq: "
         << raiz->izquierdo->valor
         << " | Hijo Der: "
         << raiz->derecho->valor << endl;

    // Llamada a la función para invertir el árbol
    invertir(raiz);

    // Resultado después de invertir
    cout << "\nDespues de invertir (Esperado: Izq 3 | Der 2):" << endl;

    // Verificación del nuevo hijo izquierdo
    if(raiz->izquierdo)
        cout << "Hijo Izq: " << raiz->izquierdo->valor;
    else
        cout << "Hijo Izq: null";

    cout << " | ";

    // Verificación del nuevo hijo derecho
    if(raiz->derecho)
        cout << "Hijo Der: " << raiz->derecho->valor << endl;
    else
        cout << "Hijo Der: null" << endl;

    return 0;
}