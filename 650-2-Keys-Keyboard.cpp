class Solution {
public:
    vector<int> dp;
    
    int minSteps(int n) {
        dp.resize(n + 1, -1);  // Initialize memoization table
        return minStepsRecursive(n);
    }

    int minStepsRecursive(int n) {
        if (n == 1) return 0;  // Base case: No operations needed for one 'A'
        const auto& ret = dp[n];
        if (ret != -1) return ret;  // Return the cached result if already computed

        dp[n] = n;  // Initialize with the maximum possible operations (n pastes after one copy)
        for (int i = n / 2; i >= 1; i--) {
            if (n % i == 0) {
                dp[n] = min(dp[n], minStepsRecursive(i) + n / i);
                break;  // Stop at the first factor to ensure the minimum steps
            }
        }

        return dp[n];
    }
};
