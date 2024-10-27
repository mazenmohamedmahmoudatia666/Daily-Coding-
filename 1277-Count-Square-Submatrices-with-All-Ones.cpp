class Solution {
     vector<vector<int>> dp; 
     vector<vector<int>>grid;
    // int dr[4] = {1 , -1 , 0 , 0};
    // int dc[4] = {0 , 0 , 1 , -1};
   int count(int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
        return 0;

    auto& ret = dp[r][c];
    if (ret != -1) {
        return ret;
    }
    
    // Use correct comparisons and calculate the size of the square
    if (grid[r][c] == 1) {
        int side = 1 + min({count(r-1, c), count(r, c-1), count(r-1, c-1)});
        ret = side; // Store the calculated size
    } else {
        ret = 0; // No square can end here
    }

    return ret;
}
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        dp.resize(rows , vector<int> (columns , -1));
        grid = matrix;

        int totalSquares = 0;
       for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            totalSquares += count(i, j);
        }
    }
    return totalSquares;
    }
};