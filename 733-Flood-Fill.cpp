
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isvalid(int r, int c, vector<vector<int>> &matrix) {
		if (r < 0 || r >= (int) matrix.size())
			return false;
		if (c < 0 || c >= (int) matrix[0].size())
			return false;
		return true;
	}
	void dfs(int r, int c, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int oldcolor, int newcolor) {
		if (!isvalid(r, c, matrix) || visited[r][c] || matrix[r][c] != oldcolor)
			return;
		visited[r][c] = true, matrix[r][c] = newcolor;
		// Implicit: jump to 4 neighbors
		dfs(r + 1, c, matrix, visited, oldcolor, newcolor);
		dfs(r - 1, c, matrix, visited, oldcolor, newcolor);
		dfs(r, c - 1, matrix, visited, oldcolor, newcolor);
		dfs(r, c + 1, matrix, visited, oldcolor, newcolor);
	}

	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
		// RxC boolean grid. Assume columns > 0
		vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
		dfs(sr, sc, image, visited, image[sr][sc], newColor);

		return image;
	}
};
