
   // graf dfs                 try to solve it mazen later 

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Helper function to count the number of islands using DFS
        auto countIslands = [&](vector<vector<int>>& grid) {
            int count = 0;
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));

            // DFS to explore the entire island starting from (r, c)
            function<void(int, int)> dfs = [&](int r, int c) {
                // Boundary and visited checks
                if (r < 0 || c < 0 || r >= rows || c >= cols || visited[r][c] || grid[r][c] == 0) {
                    return;
                }
                visited[r][c] = true; // Mark the cell as visited
                
                // Recursively visit all connected land cells
                dfs(r + 1, c); // Down
                dfs(r - 1, c); // Up
                dfs(r, c + 1); // Right
                dfs(r, c - 1); // Left
            };

            // Iterate through the grid to count the islands
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) { // Found an unvisited land cell
                        ++count;  // Increment the island count
                        dfs(i, j); // Explore this island
                    }
                }
            }
            return count; // Return the number of islands found
        };

        // Check if the grid is already disconnected (has more than 1 island)
        if (countIslands(grid) != 1) {
            return 0; // If disconnected, no need for any move
        }

        // Try removing each land cell to see if it disconnects the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) { // Found a land cell
                    grid[i][j] = 0; // Temporarily change land to water
                    if (countIslands(grid) != 1) {
                        return 1; // If grid becomes disconnected, return 1
                    }
                    grid[i][j] = 1; // Revert the change if it didn't work
                }
            }
        }

        // If the grid can't be disconnected by removing one cell, it will require 2 moves
        return 2;
    }
};
