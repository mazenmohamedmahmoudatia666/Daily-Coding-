class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int leftSum = 0;
        for(auto i : nums){
            sum+=i;
            // 28 
        }
        
        for(int i=0;i<nums.size();i++){
                
                sum-= nums[i];
              // 28 - 1  
              // 27 - 7 
              // 20 - 3
              // 17 - 6

                if(leftSum == sum ) return i;
                //   1 8
                leftSum += nums[i];
                // 11
        }
        return -1;
    }
};