class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) { // Use <= instead of <
        int mid = l + (r - l) / 2; // Calculate mid without possibility of overflow
        if (nums[mid] == target)
            return mid; // Target found
        else if (nums[mid] < target)
            l = mid + 1; // Adjust left boundary
        else
            r = mid - 1; // Adjust right boundary
    }
    return -1; // Target not found
}
};
