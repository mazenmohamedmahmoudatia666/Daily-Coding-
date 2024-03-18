class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            s += word1[i++];
            s += word2[j++];
        }
        while (i < word1.size()) {
            s += word1[i++];
        }
        while (j < word2.size()) {
            s += word2[j++];
        }
        return s;
    }
};
