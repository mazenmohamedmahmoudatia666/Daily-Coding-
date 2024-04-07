//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
	int BSfindFirst(vector<int> &nums, int val) {
		int start = 0, end = (int) nums.size() - 1, position = -1;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < val)
				start = mid + 1;
			else if (nums[mid] > val)
				end = mid - 1;
			else
				end = mid - 1, position = mid;	// Find smaller in left
		}
		return position;
	}

	int BSfindLast(vector<int> &nums, int val) {
		int start = 0, end = (int) nums.size() - 1, position = -1;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < val)
				start = mid + 1;
			else if (nums[mid] > val)
				end = mid - 1;
			else
				position = mid, start = mid + 1;	// Find higher in right
		}
		return position;
	}

	vector<int> searchRange(vector<int> &nums, int target) {
		return {BSfindFirst(nums, target), BSfindLast(nums, target), };
	}
};


