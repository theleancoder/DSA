import java.util.Iterator;
import java.util.LinkedList;

public class AdjacencyList {

	private int V;
	private LinkedList<Integer>[] list;

	public AdjacencyList(int V) {
		this.V = V;
		this.list = new LinkedList[V];
	}

	void addEdge(int u, int v) {
		if (this.list[u] != null) {
			this.list[u].add(v);
		} else {
			this.list[u] = new LinkedList<>();
			this.list[u].add(v);
		}
	}

	public void printList() {

		for (int i = 0; i < this.V; i++) {
			System.out.println("Adjacency list of vertex " + i + " is:");
			Iterator<Integer> it = this.list[i].listIterator();
			while (it.hasNext()) {
				System.out.print(it.next() + "->");
			}
			System.out.println("null\n");
		}
	}

	public static void main(String[] args) {
		AdjacencyList list = new AdjacencyList(8);

		list.addEdge(0, 1);
		list.addEdge(0, 2);
		list.addEdge(0, 3);
		list.addEdge(1, 5);
		list.addEdge(1, 6);
		list.addEdge(2, 0);
		list.addEdge(2, 4);
		list.addEdge(2, 6);
		list.addEdge(3, 0);
		list.addEdge(3, 5);
		list.addEdge(3, 7);
		list.addEdge(4, 2);
		list.addEdge(4, 7);
		list.addEdge(5, 3);
		list.addEdge(5, 7);
		list.addEdge(6, 1);
		list.addEdge(6, 2);
		list.addEdge(7, 5);
		list.addEdge(7, 3);
		list.addEdge(7, 4);

		list.printList();
	}

}
