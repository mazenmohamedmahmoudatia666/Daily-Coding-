#include <bits/stdc++.h>
using namespace std;

int getBigFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string c = \\;  // Correctly initializing the string

        // Sorting numbers based on string concatenation
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        // Iterate over sorted numbers and construct the result string
        for (int i = 0; i < nums.size(); i++) {
            c += to_string(nums[i]);
        }

        // Handle edge case when all numbers are zero
        if (c[0] == '0') return \0\;  // To avoid returning \0000\, etc.

        return c;  // Return the final concatenated string
    }
};
