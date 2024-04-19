#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

typedef vector<unordered_set<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to) {
	graph[from].insert(to);
}

void add_undirected_edge(GRAPH &graph, int from, int to) {
	graph[from].insert(to);
	graph[to].insert(from);
}

void print_adjaceny_matrix(GRAPH &graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		cout << "Node " << from << " has neighbors: ";
		for(int to : graph[from])
			cout << to << " ";
		cout << "\n";
	}
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to;
		cin >> from >> to;
		add_directed_edge(graph, from, to);
	}
	print_adjaceny_matrix(graph);
	return 0;
}

/*

6 7
2 1
2 5
2 0
2 3
0 5
1 4
5 4

Output
Node 0 has neighbors: 5
Node 1 has neighbors: 4
Node 2 has neighbors: 3 0 1 5
Node 3 has neighbors:
Node 4 has neighbors:
Node 5 has neighbors: 4

Space Complexity is O(E)
Time complexity
	O(1) for add/remove/check edge
	O(Degree) for iterate on neighbors

Disadvantages
	- No order guarantee for edges
	- Impractical for multiple edges  (we may do workarounds)
	- Hash tables extra memory
	- Like any hash tables, more caution to properly deal with the load (load factor)

 */

