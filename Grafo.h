#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
class Grafo

{
private:
	int numVertices;
	vector<list<char>> listaAdj;
	void DFS_CON_PILA(char inicio);
	void DFS_Recursivo(char inicio, std::vector<bool>& visitado, bool esPrimerVertice);
	void DFS_ciclos(char inicio, vector<bool>&visitado, queue<char>&visitados);
public:
	Grafo(int numVertices);
	void añadirArista(char origen, char destino); //Agrega una arista dirigida de origen->destino
	void mostrarGrafo();
	void DFS(char inicio, int tipo);
	void encontrarCiclos();
	
};

