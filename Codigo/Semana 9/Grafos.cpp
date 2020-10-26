// Grafos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// TDA para almacenar la lista de nodos de adyacencia
struct Node {
	int val;
	Node* next;
};

// TDA para almacenar las aristas o arcos
struct Edge {
	int src, dest;
};

class Graph
{
	// Funcion para asignar un nodo nuevo a la lista de adyacencia
	Node* getAdjListNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;

		// Apuntar nuevo nodo a la cabeza
		newNode->next = head;

		return newNode;
	}

	int N;  // Numero de nodos en grafo

public:

	// Arreglo de punteros a Nodos
	// adjacency list
	Node** head;

	// Constructor
	Graph(Edge edges[], int n, int N)
	{
		// allocate memory
		head = new Node * [N]();
		this->N = N;

		// initialize head pointer for all vertices
		for (int i = 0; i < N; i++)
			head[i] = nullptr;

		// add edges to the directed graph
		for (unsigned i = 0; i < n; i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			// insert in the beginning
			Node* newNode = getAdjListNode(dest, head[src]);

			// point head pointer to new node
			head[src] = newNode;

			// Descomentar para implementarlo para grafos no dirigidos

			/*
			newNode = getAdjListNode(src, head[dest]);

			// change head pointer to point to the new node
			head[dest] = newNode;
			*/
		}
	}

	// Destructor
	~Graph() {
		for (int i = 0; i < N; i++)
			delete[] head[i];

		delete[] head;
	}
};

// Imprimir todos los vertrices vecinos de un vertice dado
void printList(Node* ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}


int main()
{
	// Arreglo de arcos del grafo
	Edge edges[] =
	{
		// par (x, y) representan arco x a y
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// Numero de vertices del grafo
	int N = 6;

	// calcule numero de arcos
	int n = sizeof(edges) / sizeof(edges[0]);

	// constructor de grafo
	Graph graph(edges, n, N);

	// Imprimir lista de adyacencias
	for (int i = 0; i < N; i++)
	{
		// imprimi un vertice dado
		cout << i << " --";

		// imprime todos los vecinos de la lista
		printList(graph.head[i]);
	}
	char enter;
	std::cin >> enter;
	return 0;
}
