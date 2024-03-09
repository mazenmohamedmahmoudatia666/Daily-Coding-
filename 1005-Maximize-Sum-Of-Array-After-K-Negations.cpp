class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum =0 ,  mn = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i =0; i < (int)nums.size(); i++){
            if(k && nums[i] < 0)
            k -= 1 , nums[i] *= -1;
            sum += nums[i];
            mn = min(mn , nums[i]);
        }
        if(k%2)
          sum -=2*  mn;
        return sum;
    }
};