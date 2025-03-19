#include "Grafo.h"
#include <chrono>

void DFS() {
    // Crear un grafo con 5 vértices
    Grafo g(15); // Crear un grafo con 15 vértices (0 a 14)

    // Añadir aristas
    g.añadirArista(0, 1);
    g.añadirArista(0, 2);
    g.añadirArista(1, 3);
    g.añadirArista(1, 4);
    g.añadirArista(2, 5);
    g.añadirArista(2, 6);
    g.añadirArista(3, 7);
    g.añadirArista(4, 7);
    g.añadirArista(5, 8);
    g.añadirArista(6, 8);
    g.añadirArista(7, 9);
    g.añadirArista(8, 9);
    g.añadirArista(9, 10);
    g.añadirArista(10, 11);
    g.añadirArista(10, 12);
    g.añadirArista(11, 13);
    g.añadirArista(12, 13);
    g.añadirArista(13, 14);

    // Mostrar el grafo
    g.mostrarGrafo();
    auto inicio = std::chrono::high_resolution_clock::now(); // Inicio del cronómetro

g.DFS(0,1);  

// Mostrar el tiempo de ejecución


auto fin = std::chrono::high_resolution_clock::now(); // Fin del cronómetro
auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
std::cout << "\nTiempo de ejecucion: " << duracion.count() << " milliseconds" << std::endl;
}


int main() {
    DFS();
    return 0;
}