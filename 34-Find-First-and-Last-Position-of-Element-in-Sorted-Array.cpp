#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
	int BSfindFirst(vector<int> &nums, int val) {
		int start = 0, end = (int) nums.size() - 1;

		while (start < end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < val)
				start = mid + 1;
			else if (nums[mid] > val)
				end = mid - 1;
			else
				end = mid;
		}
        if(start < 0 || start >= (int)nums.size())
            return -1;
		return nums[start] == val? start : -1;
	}

	int BSfindLast(vector<int> &nums, int val) {
		int start = 0, end = (int) nums.size() - 1;

		while (start < end) {
			int mid = start + (end - start + 1) / 2;
			if (nums[mid] < val)
				start = mid + 1;
			else if (nums[mid] > val)
				end = mid - 1;
			else
				start = mid;
		}
        if(start < 0 || start >= (int)nums.size())
            return -1;
		return nums[start] == val? start : -1;
	}

	vector<int> searchRange(vector<int> &nums, int target) {
		return {BSfindFirst(nums, target), BSfindLast(nums, target), };
	}
};

