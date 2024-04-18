#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
	int from, to, weight;

	edge(int from, int to, int weight): from(from), to(to), weight(weight) {}

	bool operator < (const edge & e) const {
		return weight < e.weight;
	}

	void print() {
		cout<<"Edge ("<<from<<" "<<to<<" "<<weight<<")\n";
	}
};

typedef vector<edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost) {
	graph.push_back({from, to, cost});
}

void print_adjaceny_matrix(GRAPH &graph) {
	for (int edge = 0; edge < (int)graph.size(); ++edge)
		graph[edge].print();
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph;

	for (int e = 0; e < edges; ++e) {
		int from, to, cost;
		cin >> from >> to >> cost;
		add_edge(graph, from, to, cost);
	}
	sort(graph.begin(), graph.end());
	print_adjaceny_matrix(graph);
	return 0;
}

/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10

Output
Edge (2 1 10)
Edge (5 4 10)
Edge (2 5 20)
Edge (2 3 33)
Edge (0 5 45)
Edge (1 4 60)
Edge (2 0 77)


Space Complexity is O(E)
Time Complexity for ALL operations is O(E)
 */

