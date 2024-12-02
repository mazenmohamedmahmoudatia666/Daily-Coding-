
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
         
        int n = searchWord.size();
        int cnt = 0;
        stringstream s(sentence);
        string word;
        int idx = 1;
        while(s >> word){
            if (word.find(searchWord) == 0){
                return idx;
            }
            idx++;
        }
        
         
         return -1;
    }
};

