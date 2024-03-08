#include <vector>
#include <algorithm>
class Solution {
public:
    int largestPerimeter(vector<int>& nums) { 
        // Sort the nums vector in non-ascending order
        sort(nums.rbegin(), nums.rend());
        
        // Iterate over the nums vector
        for(int i = 0; i < (int)nums.size() - 2; i++) {
            // Check if the current triplet forms a valid triangle
            if(nums[i] < nums[i+1] + nums[i+2]) {
                // If it does, return the perimeter of the triangle
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        // If no valid triangle is found, return 0
        return 0;
    }
};
