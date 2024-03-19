class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        auto it = find(nums.begin(), nums.end(), 0);
        if (it != nums.end()) {
            // Move zeroes to the end
            int zeroCount = count(nums.begin(), nums.end(), 0);
            nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
            nums.insert(nums.end(), zeroCount, 0);
        }
    }
};
