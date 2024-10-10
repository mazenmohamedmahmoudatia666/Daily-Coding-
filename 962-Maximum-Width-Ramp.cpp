class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        stack<int> s;
        
        // Phase 1: Build a decreasing stack
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }

        // Phase 2: Iterate from the end to find maximum width ramp
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                res = max(res, i - s.top());
                s.pop();
            }
        }
        
        return res;
    }
};
