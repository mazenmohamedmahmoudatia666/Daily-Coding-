class Solution {
public:
   int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid; // Found the target
        } else if (nums[mid] < target) {
            left = mid + 1; // Adjust the left boundary
        } else {
            right = mid - 1; // Adjust the right boundary
        }
    }
    
    // If the loop exits, the target is not found in the array
    // left now indicates the index where the target should be inserted
    return left;
}
};
