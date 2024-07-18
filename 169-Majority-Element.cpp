class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 1 1 1 2 2 2 2
        int n = nums.size();
        return nums[n/2];
    }
};