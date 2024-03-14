class Solution {
public:
    int sumafterdivision(vector<int> &nums, int div) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += (nums[i] + div - 1) / div;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int division = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (sumafterdivision(nums, mid) <= threshold) {
                r = mid - 1;
                division = mid;
            } else {
                l = mid + 1;
            }
        }
        return division;
    }
};
