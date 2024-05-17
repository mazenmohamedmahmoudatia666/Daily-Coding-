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
\tvector<vector<int>> minimumAbsDifference(vector<int> &arr) {
\t\t// The min must be between consecutive values
\t\tsort(arr.begin(), arr.end());

\t\tint min_diff = INT_MAX;\t// Compute min absolute
\t\tfor (int i = 1; i < (int)arr.size(); i++)
\t\t\tmin_diff = min(min_diff, arr[i] - arr[i - 1]);

\t\t// Find consecutive values with that min dif
\t\tvector<vector<int>> res;
\t\tfor (int i = 1; i < (int)arr.size(); i++) {
\t\t\tif (arr[i] - arr[i - 1] == min_diff)
\t\t\t\tres.push_back( { arr[i - 1], arr[i] });
\t\t}
\t\treturn res;
\t}
};
