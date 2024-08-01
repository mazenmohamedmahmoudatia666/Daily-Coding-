class Solution {
public:
    int countSeniors(vector<string>& details) {
    
        int sum = 0;
        for(int i = 0; i < details.size(); i++){
         string passenger = details[i].substr(11 , 2);
         // '75' string
           int age = stoi(passenger);
            // 75 number
           if(( age > 60))
           sum++;
    }
    return sum;
    }
};