class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t pos = 0;  // Starting position in t

        for (char c : s) {
            pos = t.find(c, pos);  // Find c in t starting from pos
            if (pos == string::npos) {
                return false;  // If c is not found, return false
            }
            ++pos;  // Move to the next character in t
        }
        return true;  // All characters of s are found in t in order
    }
};