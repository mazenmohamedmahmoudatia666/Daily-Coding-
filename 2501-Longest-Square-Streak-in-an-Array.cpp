class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1;
        sort(nums.begin(), nums.end());
        vector<int> dp(1e5 + 2, 0);
        for (auto& it : nums) {
            int sq_root = sqrt(it);
            if (sq_root * sq_root == it) {
                dp[it] = 1 + dp[sq_root];
            } else {
                dp[it] = 1;
            }
            ans = max(ans, dp[it]);
        }
        return ans < 2 ? -1 : ans;
    }
};