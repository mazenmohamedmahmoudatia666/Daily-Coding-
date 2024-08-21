class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();  // Get the size of the input string
        
        // Initialize a 2D dp array where dp[i][j] represents the minimum number of turns to print substring s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        // Iterate through the string in reverse to build the solution bottom-up
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;  // Base case: A single character needs 1 turn to print
            
            // Process all substrings starting from index i and ending at index j
            for (int j = i + 1; j < n; ++j) {
                
                // Case 1: If the characters at the current start and end indices are the same
                // They can be printed together, so we carry forward the result of printing the previous part
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } 
                // Case 2: If the characters are different, we split the string at every possible position k
                // and take the minimum turns needed by combining the left and right substrings
                else {
                    for (int k = i; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        
        // Return the result stored in dp[0][n-1], which represents the minimum number of turns to print the entire string
        return dp[0][n - 1];
    }
};
