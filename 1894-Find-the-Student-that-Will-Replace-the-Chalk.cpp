class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = accumulate(chalk.begin(), chalk.end(), 0LL);  // total chalk required for one full round
        k %= total;  // Remove full rounds from k

        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;  // The student who can't receive the required chalk
            }
            k -= chalk[i];  // Subtract the current student's chalk usage
        }

        return -1;  // This line won't be reached in a valid input
    }
};
