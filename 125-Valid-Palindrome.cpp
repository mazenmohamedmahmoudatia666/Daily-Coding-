class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Traverse the string from both ends until they meet
        while (left < right) {
            // Ignore non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Ignore non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            // If characters at left and right pointers are not equal, return false
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            // Move the pointers towards each other
            left++;
            right--;
        }

        // If we reach here, the string is a palindrome
        return true;
    }
};
