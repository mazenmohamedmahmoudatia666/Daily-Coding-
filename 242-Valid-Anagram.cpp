#include <string>
#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false; // Anagrams must have the same length
        }

        map<char, int> countS;
        map<char, int> countT;

        // Count occurrences of each character in string s
        for (char ch : s) {
            countS[ch]++;
        }

        // Count occurrences of each character in string t
        for (char ch : t) {
            countT[ch]++;
        }

        // Compare counts of each character
        return countS == countT;
    }
};
