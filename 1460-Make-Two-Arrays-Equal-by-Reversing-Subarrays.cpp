class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
           sort(target.begin() , target.end());
            sort(arr.begin() , arr.end());

 
            if(arr == target)
            return true;
             return false;

            
    }
};

