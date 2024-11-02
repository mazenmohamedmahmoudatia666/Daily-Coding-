#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream s(sentence);
        string word;
        vector<string> words;
        
        // Extract each word from the sentence and store it in the vector
        while (s >> word) {
            words.push_back(word);
        }
        
        // Check if the last letter of each word matches the first letter of the next word
        for (int i = 0; i < words.size(); ++i) {
            char lastChar = words[i].back();  // Last character of the current word
            char firstChar = words[(i + 1) % words.size()].front();  // First character of the next word (circularly)
            
            if (lastChar != firstChar) {
                return false;  // If any word doesn't match, it's not circular
            }
        }
        
        return true;  // All words match circularly
    }
};

