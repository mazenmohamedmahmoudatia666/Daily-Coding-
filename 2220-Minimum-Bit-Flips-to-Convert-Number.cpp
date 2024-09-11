class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start     ^    goal;
             //    1010       0111        = 1101
        int res = 0;
        while (diff) {
            res += diff & 1;
            diff >>= 1;
        }
        return res;
    }

};