#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

/*
Another operations-based problem.
The number is a node.
We can convert to another (edge) by
	iterating on the array and applying the 3 operations

Total number of states? O(M) where M = 1001 here

Time complexity? O(M + N*M) = O(V+E) where N is the array length
*/

class Solution {
	bool process(queue<int> &q, vector<bool> &visited, int num, int goal) {
		if (num == goal)
			return true;
		if (0 <= num && num <= 1000 && !visited[num]) {
			visited[num] = true;
			q.push(num);
		}
		return false;
	}
public:
	int minimumOperations(vector<int> &nums, int start, int goal) {
		vector<bool> visited(1001);
		queue<int> q;
		q.push(start);
		visited[start] = 1;

		for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size()) {
			while (sz--) {
				int x = q.front();
				q.pop();
				for (int i = 0; i < (int) nums.size(); i++)
					if (process(q, visited, x + nums[i], goal) ||
						process(q, visited, x - nums[i], goal) ||
						process(q, visited, x ^ nums[i], goal))
						return level + 1;
			}
		}
		return -1;
	}
};


