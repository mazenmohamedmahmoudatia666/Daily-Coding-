class Solution {
public:
    long minEnd(int n, int x) {
        long result = x; // 4
        long remaining = n - 1; // 2
        long position = 1; 
        
        while (remaining) {
            // Check if the current bit position is 0 in x
            if (!(x & position)) {
                // Set the corresponding bit in result based on remaining
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            // Shift the position to check the next bit
            position <<= 1;
        }
        
        return result;
    }
};
