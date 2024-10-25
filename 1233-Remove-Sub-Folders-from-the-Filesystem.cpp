class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        
        // Sort the folder list lexicographically
        sort(folder.begin(), folder.end());
        
        for (string& i : folder) {
            // Only add `i` to `ans` if it's not a subfolder of the last added folder
            if (ans.empty() || i.substr(0, ans.back().length()) != ans.back() || i[ans.back().length()] != '/') {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
