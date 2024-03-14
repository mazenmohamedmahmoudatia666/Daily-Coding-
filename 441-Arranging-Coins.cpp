class Solution {
public:
    bool possible(int n, long long rows) {
        long sum = (rows * (rows + 1) / 2);
        return n >= sum;
    }

    int arrangeCoins(int n) {
        int l = 0;
        int r = n;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possible(n, mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
