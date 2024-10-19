class Solution {
public:
    char findKthBit(int n, int k) {
        return findKthBitRecursive(n, k);
    }
    
    char findKthBitRecursive(int n, int k) {
        if (n == 1) return '0';  // Base case: S1 is just "0"
        
        int length = (1 << n) - 1;  // Length of Sn, which is 2^n - 1
        int mid = length / 2 + 1;   // The middle position is (length / 2) + 1

        if (k == mid) {
            return '1';  // The middle bit is always '1'
        } else if (k < mid) {
            // If k is in the left half, it's the same as S_{n-1}[k]
            return findKthBitRecursive(n - 1, k);
        } else {
            // If k is in the right half, it's the inverted and reversed part
            // Calculate the mirror position in the left half and invert the result
            int mirrorK = length - k + 1;
            char mirroredBit = findKthBitRecursive(n - 1, mirrorK);
            return mirroredBit == '0' ? '1' : '0';  // Invert the bit
        }
    }
};
