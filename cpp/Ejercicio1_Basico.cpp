#include <iostream>
#include <vector>
using namespace std;

// Estructura de un nodo para un árbol N-ario
// Cada nodo almacena un valor y una lista de hijos
struct NodoN {
    int valor;
    vector<NodoN*> hijos;

    // Constructor del nodo
    NodoN(int v) : valor(v) {}
};

// Función recursiva para contar la cantidad total de nodos
int contarNodos(NodoN* raiz) {

    // Caso base:
    // Si el nodo es NULL, significa que no existe,
    // por lo tanto no aporta nodos al conteo
    if (raiz == NULL) {
        return 0;
    }

    // Se empieza contando el nodo actual
    int total = 1;

    // Recorremos todos los hijos del nodo actual
    // y sumamos recursivamente sus nodos
    for (NodoN* hijo : raiz->hijos) {
        total += contarNodos(hijo);
    }

    // Retornamos el total acumulado
    return total;
}

int main() {

    // Construcción manual del árbol N-ario

    // Nodos hoja
    NodoN* n5 = new NodoN(5);
    NodoN* n6 = new NodoN(6);

    // Nodo 2 con hijos 5 y 6
    NodoN* n2 = new NodoN(2);
    n2->hijos.push_back(n5);
    n2->hijos.push_back(n6);

    // Otros nodos hijos de la raíz
    NodoN* n3 = new NodoN(3);
    NodoN* n4 = new NodoN(4);

    // Nodo raíz
    NodoN* raiz = new NodoN(1);

    // Agregamos los hijos a la raíz
    raiz->hijos.push_back(n2);
    raiz->hijos.push_back(n3);
    raiz->hijos.push_back(n4);

    // Prueba del algoritmo
    cout << "--- Prueba Ejercicio 1 ---" << endl;
    cout << "Nodos esperados: 6" << endl;

    // Se llama a la función para contar nodos
    cout << "Nodos calculados: " << contarNodos(raiz) << endl;

    return 0;
}