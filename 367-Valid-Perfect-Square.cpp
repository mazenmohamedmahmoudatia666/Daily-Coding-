class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;

        long long l = 1, r = num; // Use long long to avoid overflow
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long square = mid * mid; // Use long long to avoid overflow
            if (square == num)
                return true; // Found the perfect square
            else if (square < num)
                l = mid + 1; // Search in the right half
            else
                r = mid - 1; // Search in the left half
        }
        return false; // If the loop exits, num is not a perfect square
    }
};
