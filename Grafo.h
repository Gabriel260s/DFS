#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <list>
#include <stack>
class Grafo

{
private:
	int numVertices;
	vector<list<int>> listaAdj;
	void DFS_CON_PILA(int inicio);
	void DFS_Recursivo(int inicio, std::vector<bool>& visitado, bool esPrimerVertice);

public:
	Grafo(int numVertices);
	void añadirArista(int origen, int destino); //Agrega una arista dirigida de origen->destino
	void mostrarGrafo();
	void DFS(int inicio, int tipo);

	
};

