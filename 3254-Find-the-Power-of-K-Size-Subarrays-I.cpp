class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n==1 || k==1) return nums; 
        vector<int> ans(n-k+1, -1); 
        int len=1; // Tracks the length of the current consecutive sequence

        for (int r=1; r < n; r++) {
            // Update len
            len=(nums[r] == nums[r-1]+1)? len+1: 1;

            // Update result if the sequence length is sufficient
            if (len >= k) {
                ans[r-k+1] = nums[r];
            //    cout<<"r="<<r<< ", ans["<<r-k+1<< "]="<<nums[r]<< endl;
            }
        }

        return ans;
    }
};