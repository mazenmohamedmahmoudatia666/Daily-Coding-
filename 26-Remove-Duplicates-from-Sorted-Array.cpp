#include <vector>
#include <algorithm> // Include the algorithm header file for std::unique

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Use unique to move duplicates to the end of the vector
        auto it = unique(nums.begin(), nums.end());
        // Erase the duplicates from the vector
        nums.erase(it, nums.end());
        // Return the size of the modified vector
        return nums.size();
    }
};
