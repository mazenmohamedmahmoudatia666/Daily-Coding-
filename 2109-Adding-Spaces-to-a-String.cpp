class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
           
            string ss;
            int  l = 0;
        for(int i = 0; i < s.size(); i++){
           if(l < spaces.size() && i == spaces[l]){
            ss += " ";
            l++;
           }
           ss+= s[i];
           
        }
        return ss;
    }
};