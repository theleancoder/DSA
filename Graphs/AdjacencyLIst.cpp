#include<iostream>
#include<list>
using namespace std;

class Graph
	{
		int V;
		list<int> *adj;
	public:
		Graph(int V)
			{
			this->V = V;
			adj = new list<int>[V];
			}
		void addEdge(int u, int v)
			{
			this->adj[u].push_back(v);
			}

		int getVertexCount()
			{
			return this->V;
			}

		list<int>* getList()
			{
			return this->adj;
			}
	};

void printList(Graph g)
	{
	list<int> *adj = g.getList();
	list<int>::iterator it;
	for(int i=0; i< g.getVertexCount(); i++)
			{
			cout << "Adjacency list of vertex " << i << " is:" <<endl;
			for(it=adj[i].begin(); it != adj[i].end(); it++)
					{
					cout << *it << "->";
					}
					cout << "null"<< endl << endl;
			}
	}

int main()
	{
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,5);
	g.addEdge(1,6);
	g.addEdge(2,0);
	g.addEdge(2,4);
	g.addEdge(2,6);
	g.addEdge(3,0);
	g.addEdge(3,5);
	g.addEdge(3,7);
	g.addEdge(4,2);
	g.addEdge(4,7);
	g.addEdge(5,3);
	g.addEdge(5,7);
	g.addEdge(6,1);
	g.addEdge(6,2);
	g.addEdge(7,5);
	g.addEdge(7,3);
	g.addEdge(7,4);

	printList(g);

	return 0;
	}
