class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
       int n = nums.size();
        vector<int> newArrOfConcatinating(2 * n); // Initialize the result vector with size 2 * n

        // Copy the elements from nums to the first half of newArrOfConcatinating
        for (int i = 0; i < n; ++i) {
            newArrOfConcatinating[i] = nums[i];
        }

        // Copy the elements from nums to the second half of newArrOfConcatinating
        for (int i = 0; i < n; ++i) {
            newArrOfConcatinating[i + n] = nums[i];
        }

        return newArrOfConcatinating;
    }
};