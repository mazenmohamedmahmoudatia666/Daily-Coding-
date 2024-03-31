#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // If the current element exists in the set, a duplicate is found within range k
            if (seen.find(nums[i]) != seen.end())
                return true;

            // Add the current element to the set
            seen.insert(nums[i]);

            // If the set size exceeds k, remove the oldest element
            if (seen.size() > k)
                seen.erase(nums[i - k]);
        }

        // No duplicates found within range k
        return false;
    }
};
