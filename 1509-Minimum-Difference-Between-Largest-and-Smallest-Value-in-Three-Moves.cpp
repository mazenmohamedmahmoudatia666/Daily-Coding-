#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        // Sort the array to make it easier to calculate differences
        sort(nums.begin(), nums.end());

        int minVal = INT_MAX;
        int n = nums.size();

        // If the array has 4 or fewer elements, we can make all elements equal
        if (n <= 4) return 0;

        // Calculate the minimum difference considering removing up to three elements
        // Remove three largest elements
        minVal = min(minVal, nums[n-4] - nums[0]);
        // Remove three smallest elements
        minVal = min(minVal, nums[n-1] - nums[3]);
        // Remove two smallest and the largest element
        minVal = min(minVal, nums[n-2] - nums[2]);
        // Remove two largest and the smallest element
        minVal = min(minVal, nums[n-3] - nums[1]);

        return minVal;
    }
};

