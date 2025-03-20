#include "Grafo.h"
#include <chrono>

void DFS() {
    // Crear un grafo con 5 v�rtices
    Grafo grafo(6); // Crear un grafo con 6 v�rtices

    // A�adir aristas
    grafo.a�adirArista('A', 'B');
    grafo.a�adirArista('A', 'D');
    grafo.a�adirArista('B', 'C');
    grafo.a�adirArista('B', 'E');
    grafo.a�adirArista('D', 'E');
    grafo.a�adirArista('E', 'F');
    grafo.a�adirArista('F', 'A');

    // Mostrar el grafo
    grafo.mostrarGrafo();
    auto inicio = std::chrono::high_resolution_clock::now(); // Inicio del cron�metro
    grafo.DFS('A', 0);

    //Ciclos en el grafo:
    cout << "\n\nEste grafo tiene ciclos?" << endl;
    grafo.encontrarCiclos();
    

    // Mostrar el tiempo de ejecuci�n
    auto fin = std::chrono::high_resolution_clock::now(); // Fin del cron�metro
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    std::cout << "\nTiempo de ejecucion: " << duracion.count() << " microseconds (" << duracion.count()/1000 << " milliseconds) " << std::endl;
}


int main() {
    DFS();
    return 0;
}