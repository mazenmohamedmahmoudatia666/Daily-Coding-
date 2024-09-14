class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       // sort(nums.begin(), nums.end());
    auto max_it = std::max_element(nums.begin(), nums.end());
    int k = *max_it;
        int n = nums.size();
        int cnt = 0, maxx = 0;
         for(int i  = 0; i < nums.size(); i++){
            if(nums[i] == k){
            cnt++;
             maxx = max(cnt , maxx);
         }else cnt= 0;

         }
         return maxx;
    }
};