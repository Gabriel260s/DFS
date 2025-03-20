#include "Grafo.h"
#include <chrono>

void DFS() {
    // Crear un grafo con 5 vértices
    Grafo grafo(6); // Crear un grafo con 6 vértices

    // Añadir aristas
    grafo.añadirArista('A', 'B');
    grafo.añadirArista('A', 'D');
    grafo.añadirArista('B', 'C');
    grafo.añadirArista('B', 'E');
    grafo.añadirArista('D', 'E');
    grafo.añadirArista('E', 'F');
    grafo.añadirArista('F', 'A');

    // Mostrar el grafo
    grafo.mostrarGrafo();
    auto inicio = std::chrono::high_resolution_clock::now(); // Inicio del cronómetro
    grafo.DFS('A', 0);

    //Ciclos en el grafo:
    cout << "\n\nEste grafo tiene ciclos?" << endl;
    grafo.encontrarCiclos();
    

    // Mostrar el tiempo de ejecución
    auto fin = std::chrono::high_resolution_clock::now(); // Fin del cronómetro
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    std::cout << "\nTiempo de ejecucion: " << duracion.count() << " microseconds (" << duracion.count()/1000 << " milliseconds) " << std::endl;
}


int main() {
    DFS();
    return 0;
}