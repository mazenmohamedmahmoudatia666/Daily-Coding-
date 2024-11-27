#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Adjacency list to represent the graph
        vector<vector<int>> adj(n);

        // Initially, add roads from city i to city i + 1
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }

        // Result vector to store the shortest path after each query
        vector<int> result;

        // Process each query
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            // Add the new road from u to v
            adj[u].push_back(v);

            // After each query, compute the shortest path from city 0 to city n-1
            result.push_back(bfs(n, adj));
        }

        return result;
    }

private:
    int bfs(int n, const vector<vector<int>>& adj) {
        vector<int> dist(n, INT_MAX);  // Distance array, initialized to infinity
        queue<int> q;
        
        // Start BFS from city 0
        dist[0] = 0;
        q.push(0);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            // Explore all neighbors
            for (int neighbor : adj[cur]) {
                if (dist[neighbor] == INT_MAX) {  // If neighbor hasn't been visited
                    dist[neighbor] = dist[cur] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Return the distance to city n-1, or -1 if unreachable
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};

