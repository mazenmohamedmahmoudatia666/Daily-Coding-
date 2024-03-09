// count sort 
// time O(n + m)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Find the minimum and maximum values in nums
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());
        
        // Compute Frequency using vector
        vector<int> count(maxValue - minValue + 1); // Create a count vector with appropriate size
    
        for (int num : nums)
            count[num - minValue]++;
        
        // Put the sorted values back to the array
        int idx = 0;
        for (int i = minValue; i <= maxValue; ++i) {
            for (int j = 0; j < count[i - minValue]; ++j)
                nums[idx++] = i;
        }
        return nums;
    }
};
