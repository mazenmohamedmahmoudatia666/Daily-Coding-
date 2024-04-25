class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false; // Handle empty matrix case
        
        int cols = matrix[0].size();
        int l = 0, r = rows * cols - 1; // Initialize l and r to the first and last element indices
        
        while (l <= r) { // Use <= for binary search condition
            int mid = l + (r - l) / 2;
            int midVal = matrix[mid / cols][mid % cols]; // Convert 1D index to 2D index
            
            if (midVal == target) {
                return true; // Target found
            } else if (midVal < target) {
                l = mid + 1; // Move to the right half
            } else {
                r = mid - 1; // Move to the left half
            }
        }
        
        return false; // Target not found
    }
};