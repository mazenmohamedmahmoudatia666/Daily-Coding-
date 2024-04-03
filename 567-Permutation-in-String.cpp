#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int word1 = s1.size();
        int word2 = s2.size();
        if (word1 > word2)
            return false; // If s1 is larger than s2, s1 cannot be a permutation of any substring of s2
        
        unordered_map<char, int> freq_s1, freq_s2;
        
        // Initialize frequency maps for s1 and the substring of s2
        for (char c : s1) {
            freq_s1[c]++;
        }
        for (int i = 0; i < word1; ++i) {
            freq_s2[s2[i]]++;
        }
        
        // Check if the initial substring of s2 is a permutation of s1
        if (freq_s1 == freq_s2)
            return true;
        
        // Move the sliding window and update frequency map for substring of s2
        for (int i = word1; i < word2; ++i) {
            freq_s2[s2[i]]++;
            freq_s2[s2[i - word1]]--;
            if (freq_s2[s2[i - word1]] == 0) {
                freq_s2.erase(s2[i - word1]);
            }
            if (freq_s1 == freq_s2) {
                return true;
            }
        }
        
        return false; // If no permutation found
    }
};


