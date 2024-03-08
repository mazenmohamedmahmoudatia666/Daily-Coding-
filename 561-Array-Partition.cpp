class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int max_sum = 0;

        for(int i = 0; i < (int)nums.size(); i+=2){
            max_sum += nums[i];
        }
         return max_sum;
    }

};