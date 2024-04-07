#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int> &v, int target) {
		auto p = equal_range(v.begin(), v.end(), target);

		if (p.first == v.end())
			return {-1, -1};

        int x = p.first - v.begin();    // first >=
        int y = p.second - v.begin();   // first >   -1 to get last

        if (v[x] != target)
            return {-1, -1};

		return {x, y-1};
	}
};
