#include <vector>

class Solution {
public:
    int arraySign(std::vector<int>& nums) {
        int product = 1;

        for (auto& num : nums) {
            if (num == 0) return 0;  // If any number is zero, the product is zero
            product *= (num > 0) ? 1 : -1;  // Multiply by 1 if positive, -1 if negative
        }

        return (product > 0) ? 1 : -1;
    }
};
