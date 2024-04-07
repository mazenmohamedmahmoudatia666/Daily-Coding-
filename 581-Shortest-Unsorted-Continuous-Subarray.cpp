class Solution {
public:
	int findUnsortedSubarray(vector<int> &nums) {	// O(nlogn) time - O(n) space
		vector<int> sorted = nums;
		sort(sorted.begin(), sorted.end());

		int left = -1, right = -1;
		for (int i = 0; i < (int)nums.size(); i++) {
			if (nums[i] != sorted[i]) {
				if (left == -1)	// first one is min
					left = i;
				else
					right = i;	// keep updating the right
			}
		}
		if (left == -1)
			return 0;
		return right - left + 1;
	}
};
