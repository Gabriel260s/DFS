#include "Grafo.h"

Grafo::Grafo(int numVertices)
{
	this->numVertices = numVertices;
	listaAdj = vector<std::list<char>>(numVertices);
}

void Grafo::añadirArista(char origen, char destino)
{
	listaAdj[origen-65].push_back(destino);
}

void Grafo::mostrarGrafo()
{
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertice " << (char) (i + 65) << " esta conectado con: ";
        for (const char& vecino : listaAdj[i]) {
            std::cout << vecino << " ";
        }
        std::cout << std::endl;
    }
}


//DFS no recursivo usando una pila
void Grafo::DFS_CON_PILA(char inicio)
{
    vector<bool> visitado(numVertices, false); //Vector para marcar vertices visitados
    stack<char> pila;

    //Marcamos el inicio como visitado y lo agregamos a la pila
    visitado[inicio-65] = true;
    pila.push(inicio);

    while (!pila.empty()) {
        char actual = pila.top(); pila.pop();
        cout << actual;
        for (const char& vecino : listaAdj[actual-65]) {
            if (!visitado[vecino-65]) {
                visitado[vecino-65] = true;
                pila.push(vecino);
            }
        }
        if (!pila.empty()) {
            cout << " --> ";
        }
    }
    cout << endl; // Salto de línea al final   
}


void Grafo::DFS_Recursivo(char inicio, vector<bool>&visitado, bool esPrimerVertice = true) {
    // Marcar el vértice actual como visitado
    visitado[inicio-65] = true;
   
    if (!esPrimerVertice) {
        std::cout << " --> ";
    }

    // Imprimir el vértice actual
    cout << inicio;

    // Recorrer todos los vecinos del vértice actual
    for (const char& vecino : listaAdj[inicio-65]) {
        if (!visitado[vecino-65]) {
            DFS_Recursivo(vecino, visitado, false); // Llamada recursiva
        }
    }
}


void Grafo::DFS(char inicio, int tipo)
{
	vector<bool> visitado(numVertices, false); //Vector para marcar vertices visitados
    if (tipo == 0) {
        DFS_Recursivo(inicio, visitado);
    }
    else if (tipo == 1) {
        DFS_CON_PILA(inicio);
    }
}

void Grafo::DFS_ciclos(char inicio, vector<bool>& visitado, queue<char>&visitados) {
    // Marcar el vértice actual como visitado
    visitado[inicio-65] = true;
    visitados.push(inicio);
    // Recorrer todos los vecinos del vértice actual
    for (const char& vecino : listaAdj[inicio-65]) {
        if (!visitado[vecino - 65]) {
            if (vecino == visitados.front()) {
                cout << "Hay un ciclo al nodo " << vecino << endl;
            }
            DFS_ciclos(vecino, visitado, visitados); // Llamada recursiva
        }
    }
}

void Grafo::encontrarCiclos() {
    vector<bool> visitado(numVertices, false);
    queue<char> visitados;
    DFS_ciclos(listaAdj[0].front(), visitado, visitados);
}
