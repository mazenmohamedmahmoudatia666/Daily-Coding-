
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
        


class Solution {
bool canEatAll(const vector<int>& piles, int k, int h) {
    int time_taken = 0;
    for (int pile : piles) {
        time_taken += (pile + k - 1) / k;
    }             
    return time_taken <= h;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, mid, h)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
};