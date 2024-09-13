class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n + 1, 0); // Prefix XOR array
        
        // Compute prefix XOR array
        for (int i = 0; i < n; ++i) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
        vector<int> res;
        res.reserve(queries.size()); // Reserve space for results
        
        // Answer each query using the prefix XOR array
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            int result = prefixXor[right + 1] ^ prefixXor[left];
            res.push_back(result);
        }
        
        return res;
    }
};
