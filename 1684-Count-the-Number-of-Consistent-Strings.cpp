class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
    set<char>s;
    for(char&c : allowed){
        s.insert(c);
    }
    int cnt = 0;
    for(int i = 0; i < words.size(); i++){
        bool flag = true;
        for(char &k : words[i]){
        if(s.find(k) == s.end()){
            flag = false;
            break;
        }   
    }
        if(flag) cnt++;
    }
    return cnt;
    }

};