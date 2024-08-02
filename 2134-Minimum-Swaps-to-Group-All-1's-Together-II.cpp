class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int totalones = 0;
       int n = nums.size();
       //  7

       for(int num : nums){
        if(num == 1)totalones++;
        //  3
       }

       if(totalones == 0 || totalones == n)
       return 0;

        int maxones = 0 , currentones = 0;

        for(int i = 0; i < totalones; i++){
          if( nums[i] == 1) currentones++;
               
        }
        maxones = currentones;

        for(int i = totalones ; i < n + totalones; i++){
            if(nums[i % n] == 1) currentones++;
            if(nums[i-totalones] % n == 1)currentones--;
            maxones = max(maxones , currentones);
        }


        return totalones - maxones;

       


       

    }
};