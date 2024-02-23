#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

/*
 * We care about the minimum between every pair
 * This min pair must be the closest to each other
 * Such pair can be trivially found in a sorted array
 *
 * - Sort
 * - Find the min difference
 * - Get all such pairs from the sorted array
 * 
 * O(nlogn) time compleixty, O(1) space 
 */

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
		// The min must be between consecutive values
		sort(arr.begin(), arr.end());

		int min_diff = INT_MAX;	// Compute min absolute
		for (int i = 1; i < (int)arr.size(); i++)
			min_diff = min(min_diff, arr[i] - arr[i - 1]);

		// Find consecutive values with that min dif
		vector<vector<int>> res;
		for (int i = 1; i < (int)arr.size(); i++) {
			if (arr[i] - arr[i - 1] == min_diff)
				res.push_back( { arr[i - 1], arr[i] });
		}
		return res;
	}
};

int main() {

	return 0;
}

