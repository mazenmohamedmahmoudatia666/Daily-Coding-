class Solution {
public:
    int takeCharacters(string s, int k) {
        // Step 1: Count total occurrences of each character
        unordered_map<char, int> total;
        for (char c : s) {
            total[c]++;
        }

        // Step 2: Check if the task is impossible
        if (total['a'] < k || total['b'] < k || total['c'] < k) {
            return -1; // Not enough characters to satisfy k
        }

        // Step 3: Sliding window to find the largest valid window
        int n = s.size();
        unordered_map<char, int> window;
        int left = 0, maxWindow = 0;

        for (int right = 0; right < n; right++) {
            window[s[right]]++;

            // Shrink the window if invalid
            while (total['a'] - window['a'] < k ||
                   total['b'] - window['b'] < k ||
                   total['c'] - window['c'] < k) {
                window[s[left]]--;
                left++;
            }

            // Update the maximum valid window size
            maxWindow = max(maxWindow, right - left + 1);
        }

        // Step 4: Minimum substring to remove is the complement of maxWindow
        return n - maxWindow;
    }
};
