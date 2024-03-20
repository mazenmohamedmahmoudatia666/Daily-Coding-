#include <vector>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    }
    
private:
    void backtrack(const vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset); // Add the current subset to the result
        
        // Explore all possible subsets that can be formed by adding elements from 'start' to the end
        for (int i = start; i < nums.size(); ++i) {
            // Add nums[i] to the current subset
            subset.push_back(nums[i]);
            // Explore further to generate subsets with nums[i] included
            backtrack(nums, i + 1, subset, result);
            // Backtrack and remove nums[i] from the current subset to explore other possibilities
            subset.pop_back();
        }
    }
};
