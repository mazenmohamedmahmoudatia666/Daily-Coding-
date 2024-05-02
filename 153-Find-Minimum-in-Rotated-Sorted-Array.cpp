class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int minn = *min_element(nums.begin(), nums.end());
        
        return minn; 
    }
};