#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

/*
 *                       0  1  2  3 4  5  6  7  8  9   10
 * Assume given array:  10 20 30 40 50 90 80 70 60 100 111
 * Assume sorted array: 10 20 30 40 50 60 70 80 90 100 111
 * 
 *
 * We can think of the array as 3 parts
 * A) Left Increasing Subarray matching sorted array: prefix 10 20 30 40 50
 * B) The shortest subarray we should sort: 90 80 70 60
 * C) Right Increasing Subarray matching sorted array: postfix 100 111
 * 
 * In a sorted array, what makes A[i] is in its right location?
 * 	 A[i] is >= all previous elments
 * 	 A[i] is <= all next elments
 * 
 * We want to find the first element of C[0]:
 * 	That is: a sorted subarray and all its values are >= all the older values
 * 
 * How can we find that in an efficient way?
 * 	Iterate and keep the maximum. Whenever the mxSofar > nums[i]: it means this nums[i] can't be part of C
 * 	Find the smallest i such that: the remaining is valid postfix
 *
 * 	In other words: "In the first pass (front to back), the algorithm looks for the last item that's out-of-order.
 * 		It determines whether something's out of order by tracking the maximum value seen so far during the traversal
 * 		and comparing it to the current value", by Xyzzy123
 *
 * The same logic, but opposite direction for A
 *
 * In the editorial, Approach 5, there is another nice solution, but it needs 4 loops instead of 2
 */

class Solution {
public:

	int findUnsortedSubarray(vector<int> &nums) {	// O(n) time - O(1) space
		int mxSofar = INT_MIN, mnSofar = INT_MAX;
		int left = -1, right = -1;
		// Find the smallest i such that: the remaining is valid postfix
		for (int i = 0; i < (int) nums.size(); ++i) {
			mxSofar = max(mxSofar, nums[i]);
			if (mxSofar > nums[i])
				right = i;
		}
		// Find the largest i such that: the remaining is valid prefix
		for (int i = (int) nums.size() - 1; i >= 0; --i) {
			mnSofar = min(mnSofar, nums[i]);
			if (mnSofar < nums[i])
				left = i;
		}
		if (right == -1)
			return 0;
		return right - left + 1;
	}
};


