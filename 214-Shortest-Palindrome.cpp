class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = string(s.rbegin(), s.rend());  // Reverse of the string s
        string combined = s + \#\ + rev_s;            // Combine s and its reverse with a separator

        // Compute the prefix function for the combined string (KMP algorithm)
        int n = combined.size();
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            int j = prefix[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = prefix[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            prefix[i] = j;
        }

        // The length of the longest palindrome prefix is stored in the last value of prefix array
        int longest_palindrome_prefix = prefix[n - 1];

        // Append the reverse of the remaining part of s to the front
        return rev_s.substr(0, s.size() - longest_palindrome_prefix) + s;
    }
};