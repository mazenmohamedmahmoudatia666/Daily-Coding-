class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the dimensions are valid
        if (m * n != original.size())
            return {}; // Return an empty array if dimensions don't match

        vector<vector<int>> twod(m, vector<int>(n)); // Initialize 2D vector with m rows and n columns
        
        for (int i = 0; i < original.size(); i++) {
            // Map the 1D array index to 2D array
            int row = i / n;
            int col = i % n;
            twod[row][col] = original[i]; // Assign the value from the original array
        }

        return twod;
    }
};
