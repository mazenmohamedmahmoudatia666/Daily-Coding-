#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> substringCount;
        int n = s.size();
        int maxLength = -1;

        // Check substrings of length 1 to n (all special substrings)
        for (int length = 1; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                string sub = s.substr(i, length);
                
                // Check if the substring is "special" (i.e., all characters are the same)
                if (isSpecial(sub)) {
                    substringCount[sub]++;
                    if (substringCount[sub] >= 3) {
                        maxLength = max(maxLength, length);
                    }
                }
            }
        }

        return maxLength;
    }

private:
    // Helper function to check if a substring is "special" (all characters are the same)
    bool isSpecial(const string& s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i-1]) {
                return false;
            }
        }
        return true;
    }
};
