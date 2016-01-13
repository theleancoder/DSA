#include<iostream>
#include<list>
using namespace std;

class Graph {
		int V;
		list<int> *adj;
	public:
		Graph(int V) {
			this->V = V;
			adj = new list<int>[V];
		}
		void addEdge(int u, int v) {
			this->adj[u].push_back(v);
		}
		
		int getVertexCount() {
			return this->V;
		}
		
		list<int>* getList() {
			return this->adj;
		}
};

void bfs(Graph g, int s, bool visited[]) {
	list<int> *adj = g.getList();
	list<int> queue;
	
	visited[s] = true;
	queue.push_back(s);
	
	list<int>::iterator it;
	
	while(!queue.empty()) {
		int v = queue.front();
		cout << v << ' ';
		queue.pop_front();
		
		for(it = adj[v].begin(); it != adj[v].end(); it++) {
			if(!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}

void connectedComponents(Graph g) {
	int V = g.getVertexCount();
	bool visited[V];
	
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}
	
	int c = 0;
	
	for(int i = 0; i < V; i++) {
		if(visited[i] == false) {
			c = c + 1;
			cout << "Component: " << c << endl;
			bfs(g, i, visited);
			cout << endl;
		}
	}
	
}

int main() {
	Graph g(8);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 0);
	g.addEdge(2, 0);
	g.addEdge(2, 4);
	g.addEdge(3, 7);
	g.addEdge(4, 2);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(6, 5);
	g.addEdge(7, 3);
	g.addEdge(7, 6);
	
	connectedComponents(g);
	return 0;
}
