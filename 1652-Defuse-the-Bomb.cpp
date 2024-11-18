class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> v; // Result vector
        int original_k = k; // Store the original value of k

        for (int i = 0; i < n; i++) {
            int sum = 0;
            k = original_k; // Reset k for each `i`

            if (k > 0) {
                int j = i + 1; // Start summing from the next index
                while (k > 0) {
                    sum += code[j % n]; // Use circular indexing
                    j++;
                    k--;
                }
            } else if (k < 0) {
                int j = i - 1; // Start summing from the previous index
                while (k < 0) {
                    sum += code[(j + n) % n]; // Use circular indexing to handle negative indices
                    j--;
                    k++;
                }
            }

            v.push_back(sum);
        }

        return v;
    }
};
