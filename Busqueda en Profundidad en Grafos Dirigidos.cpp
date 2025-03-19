#include "Grafo.h"
#include <chrono>

void DFS() {
    // Crear un grafo con 5 v�rtices
    Grafo g(15); // Crear un grafo con 15 v�rtices (0 a 14)

    // A�adir aristas
    g.a�adirArista(0, 1);
    g.a�adirArista(0, 2);
    g.a�adirArista(1, 3);
    g.a�adirArista(1, 4);
    g.a�adirArista(2, 5);
    g.a�adirArista(2, 6);
    g.a�adirArista(3, 7);
    g.a�adirArista(4, 7);
    g.a�adirArista(5, 8);
    g.a�adirArista(6, 8);
    g.a�adirArista(7, 9);
    g.a�adirArista(8, 9);
    g.a�adirArista(9, 10);
    g.a�adirArista(10, 11);
    g.a�adirArista(10, 12);
    g.a�adirArista(11, 13);
    g.a�adirArista(12, 13);
    g.a�adirArista(13, 14);

    // Mostrar el grafo
    g.mostrarGrafo();
    auto inicio = std::chrono::high_resolution_clock::now(); // Inicio del cron�metro

g.DFS(0,1);  

// Mostrar el tiempo de ejecuci�n


auto fin = std::chrono::high_resolution_clock::now(); // Fin del cron�metro
auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
std::cout << "\nTiempo de ejecucion: " << duracion.count() << " milliseconds" << std::endl;
}


int main() {
    DFS();
    return 0;
}