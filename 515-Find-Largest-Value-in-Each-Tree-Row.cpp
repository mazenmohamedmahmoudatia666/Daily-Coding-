class Solution {
    vector<int> bfs(TreeNode* root) {
        if(!root) return vector<int>();
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;

        while(!q.empty()) {
            int sz = q.size();
            int maxValue = INT_MIN;

            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
 

                maxValue = max(maxValue, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(maxValue);
        }
        return result;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        return bfs(root);
    }
};
