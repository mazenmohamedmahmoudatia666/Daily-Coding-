#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> money;
vector<vector<int>> dp;

int countWays(int amount, int start) {
    if (amount == 0) return 1;      // One way to make 0 amount
    if (amount < 0) return 0;       // No way to make negative amount

    int &ret = dp[amount][start];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = start; i < money.size(); ++i) {
        ret += countWays(amount - money[i], i);  // Only use coins from the current position onwards
    }
    return ret;
}

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        money = coins;
        dp.assign(amount + 1, vector<int>(coins.size(), -1));  // 2D dp to track amount and start position

        return countWays(amount, 0);   // Start from 0th coin
    }
};
