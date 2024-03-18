class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // Zero and negative numbers are not powers of three
        while (n % 3 == 0) { // Keep dividing by 3 until n is no longer divisible by 3
            n /= 3;
        }
        return n == 1; // If n becomes 1, it means it was a power of three
    }
};
