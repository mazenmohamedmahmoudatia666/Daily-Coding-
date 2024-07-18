#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()); // Set for unique elements in nums1
        set<int> s2(nums2.begin(), nums2.end()); // Set for unique elements in nums2
        
        vector<int> diff1, diff2;
        
        // Find elements in s1 that are not in s2
        for (int num : s1) {
            if (s2.find(num) == s2.end()) {
                diff1.push_back(num);
            }
        }
        
        // Find elements in s2 that are not in s1
        for (int num : s2) {
            if (s1.find(num) == s1.end()) {
                diff2.push_back(num);
            }
        }
        
        return {diff1, diff2};
    }
};


