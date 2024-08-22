class Solution {
public:
    int findComplement(int n) {
        unsigned int highestBit = 1 << (int)(log2(n));
        unsigned int mask = (highestBit * 2) - 1;
        return n ^ mask;
    }
};