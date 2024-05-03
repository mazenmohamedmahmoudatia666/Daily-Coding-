
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*
 * Imagine we have pairs representing (0, 3), (3, 6), (6, 9), (9, 12)
 *
 * Given that we can swap the characters at any pair of indices in the given pairs any number of times
 * This means, we can move any character in the chain of indices [0, 3, 6, 9, 12]
 *
 * Imagine that every pair is a graph edge, then in every component, we can order its character in whatever order
 * Please find try some examples to convenience yourself
 *
 * Now we can do the following:
 * 	1- Build the undirected graph
 * 	2- Find CCs
 * 	3- For each CC, order its characters to be smallest lexicographically (aka sorted)
 *
 * 	Nodes are huge, keep the graph processing linear in terms of E/V
 */

typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to) {
	graph[from].push_back(to);
	graph[to].push_back(from);
}

// Coding tip: Keep your functions standard for reusability
void dfs(GRAPH &graph, int node, vector<bool> &visited, vector<int> &cc_nodes) {
	visited[node] = true;
	cc_nodes.push_back(node);

	for (int neighbour : graph[node]) {
		if (!visited[neighbour])
			dfs(graph, neighbour, visited, cc_nodes);
	}
}

class Solution {
public:

	string smallestStringWithSwaps(string str, vector<vector<int>> &pairs) {
		int nodes = str.size();
		GRAPH graph(nodes);

		// Build graph edges
		for (int i = 0; i < (int) pairs.size(); ++i)
			add_undirected_edge(graph, pairs[i][0], pairs[i][1]);

		vector<bool> visited(nodes);

		// Without sorting, total O(E+V). Be careful to not get TLE
		for (int i = 0; i < nodes; i++) {	// Find CCs
			if (!visited[i]) {
				vector<int> cc_nodes;
				dfs(graph, i, visited, cc_nodes);

				// Get String of this CC. We can make this addition to the DFS itself.
				string cc_letters;
				for(int node : cc_nodes)
					cc_letters += str[node];

				// We can rearrange these letters in anyway as they are connected
				// Use the sorting order
				sort(cc_nodes.begin(), cc_nodes.end());
				sort(cc_letters.begin(), cc_letters.end());

				for (int j = 0; j < (int) cc_nodes.size(); j++)
					str[cc_nodes[j]] = cc_letters[j];
			}
		}
		return str;
	}
};

