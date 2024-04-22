//https://leetcode.com/problems/number-of-closed-islands/


#include<iostream>
#include<vector>
using namespace std;

/*
 * A simple observation will make this problem just a standard code!
 *
 * What REALLY makes a connected component closed?
 * 	Simply, it doesn't touch any grid boundary at all (first/last row - first/last column)
 *
 * So do the normal CC counting on DFS for the zero values
 * 		Any CC that touches the boundary shouldn't be counted
 *
 * For educational purposes only, instead of building visited matrix
 * I build CC matrix, which assigns the same ID for all CC elements
 * 		Start from id=1 to differentiate which cells NOT visited
 */

class Solution {
private:
	int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };

	bool is_touched_boundry;

public:
	int isvalid(int r, int c, vector<vector<int>> &grid) {
		if (r < 0 || r >= (int) grid.size())
			return false;
		if (c < 0 || c >= (int) grid[0].size())
			return false;
		return true;
	}

	bool isGridBoundry(int r, int c, vector<vector<int>> &grid) {
		if (r == 0 || r == (int) grid.size() - 1)
			return true;	// first or last row
		if (c == 0 || c == (int) grid[0].size() - 1)
			return true;	// first or last column
		return false;
	}

	void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &ccIDs, int ccid) {
		if (!isvalid(r, c, grid) || ccIDs[r][c] || grid[r][c] == 1)
			return;		// invalid, visited or non-CC

		if (isGridBoundry(r, c, grid))
			is_touched_boundry = true;

		ccIDs[r][c] = ccid;	// assign this ID to this CC
		for (int d = 0; d < 4; ++d)
			dfs(r + dr[d], c + dc[d], grid, ccIDs, ccid);
	}

	int closedIsland(vector<vector<int>> &grid) {
		vector<vector<int>> ccIDs(grid.size(), vector<int>(grid[0].size()));
		int rows = grid.size(), cols = grid[0].size(), ccid = 0, count = 0;

		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				if (!grid[r][c] && !ccIDs[r][c]) {	// New CC component of ZEROs
					is_touched_boundry = false;
					dfs(r, c, grid, ccIDs, ++ccid);
					count += !is_touched_boundry;
				}
			}
		}
		return count;
	}
};


