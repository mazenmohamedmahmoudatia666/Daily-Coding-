class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
        return false;
      string m = s;
       for(int i = 0; i <s.size(); i++){
           m += s[i];
       }
              if(m.find(goal) != string::npos)
              return true;
            else return false;

    }
};

   // testcase 1 abcdeabcde


 //testcase 2 abcdeabcde

