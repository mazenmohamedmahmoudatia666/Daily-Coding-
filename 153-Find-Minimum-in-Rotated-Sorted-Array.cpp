class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int minn = *min_element(nums.begin(), nums.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == minn)
                return minn;
            else if (nums[mid] < minn) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return minn; // If min element not found
    }
};