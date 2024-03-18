class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true; // Base case: 3^0 = 1
        if (n <= 0 || n % 3 != 0) return false; // If n is not positive or not divisible by 3, it's not a power of three
        
        return isPowerOfThree(n / 3); // Recursively check if n / 3 is a power of three
    }
};
