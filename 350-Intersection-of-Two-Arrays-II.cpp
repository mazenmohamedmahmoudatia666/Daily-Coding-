#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        // Sort both input arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // Use two pointers to traverse the sorted arrays
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return res;
    }
};

