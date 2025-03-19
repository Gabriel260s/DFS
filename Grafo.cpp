#include "Grafo.h"

Grafo::Grafo(int numVertices)
{
	this->numVertices = numVertices;
	listaAdj = vector<std::list<int>>(numVertices);
}

void Grafo::añadirArista(int origen, int destino)
{

	listaAdj[origen].push_back(destino);
}

void Grafo::mostrarGrafo()
{
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertice " << i << " esta conectado con: ";
        for (const auto& vecino : listaAdj[i]) {
            std::cout << vecino << " ";
        }
        std::cout << std::endl;
    }

}


void Grafo::DFS_CON_PILA(int inicio)
{
    vector<bool> visitado(numVertices, false); //Vector para marcar vertices visitados
    stack<int>pila;

    //Marcamos el inicio como visitado y lo agregamos a la pila
    visitado[inicio] = true;
    pila.push(inicio);


    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();
        cout << actual;
        for (const auto& vecino : listaAdj[actual]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                pila.push(vecino);
            }
        }
         if (!pila.empty()) {
            cout << " --> ";
        }
    }
    cout << endl; // Salto de línea al final

    
}

void Grafo::DFS_Recursivo(int inicio, std::vector<bool>& visitado, bool esPrimerVertice = true) {
    // Marcar el vértice actual como visitado
    visitado[inicio] = true;

   
    if (!esPrimerVertice) {
        std::cout << " -> ";
    }

    // Imprimir el vértice actual
    cout << inicio;

    // Recorrer todos los vecinos del vértice actual
    for (const auto& vecino : listaAdj[inicio]) {
        if (!visitado[vecino]) {
            DFS_Recursivo(vecino, visitado, false); // Llamada recursiva
        }
    }
}
void Grafo::DFS(int inicio, int tipo)
{
	vector<bool> visitado(numVertices, false); //Vector para marcar vertices visitados
	if (tipo == 1) {
		DFS_CON_PILA(inicio);
	}
	else {
		DFS_Recursivo(inicio, visitado);
	}
}
