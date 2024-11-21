class Solution {
    int dr[4] = {0, 0, -1, 1}; // Direction arrays for rows and columns
    int dc[4] = {-1, 1, 0, 0}; 

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // Grid initialization

        // Mark guards and walls on the grid
        for (auto& g : guards)
            grid[g[0]][g[1]] = 1; // Mark guard as 1
        for (auto& w : walls)
            grid[w[0]][w[1]] = 2; // Mark wall as 2

        // Mark cells guarded by guards
        for (auto& g : guards) {
            for (int d = 0; d < 4; d++) {
                int r = g[0], c = g[1];
                while (true) {
                    r += dr[d];
                    c += dc[d];
                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1 || grid[r][c] == 2)
                        break; // Stop if out of bounds, at a guard, or at a wall
                    if (grid[r][c] == 0)
                        grid[r][c] = -1; // Mark as guarded
                }
            }
        }

        // Count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    unguarded++; // Count cells that are neither guarded, walls, nor guards
            }
        }

        return unguarded;
    }
};
