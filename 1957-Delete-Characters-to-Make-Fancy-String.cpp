class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                count = 1;  // Reset count for a new character
            } else {
                count++;  // Increment count for consecutive characters
            }

            // Append only if count is <= 2
            if (count <= 2) {
                result += s[i];
            }
        }
        
        return result;
    }
};
