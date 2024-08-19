class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1; // The first ugly number is 1

        vector<int> dp(n); // DP array to store ugly numbers
        dp[0] = 1; // Initialize the first ugly number

        int i2 = 0, i3 = 0, i5 = 0; // Pointers for multiples of 2, 3, and 5

        for (int i = 1; i < n; i++) {
            // Calculate possible next ugly numbers
            int next2 = dp[i2] * 2;
            int next3 = dp[i3] * 3;
            int next5 = dp[i5] * 5;

            // Choose the smallest number to be the next ugly number
            dp[i] = min(next2, min(next3, next5));

            // Move the corresponding pointer(s)
            if (dp[i] == next2) i2++;
            if (dp[i] == next3) i3++;
            if (dp[i] == next5) i5++;
        }

        // The nth ugly number is the last element in the dp array
        return dp[n-1];
    }
};
