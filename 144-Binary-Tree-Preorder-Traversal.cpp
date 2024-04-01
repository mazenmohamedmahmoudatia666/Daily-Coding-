#include <vector>



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root)
            return;
             TreeNode *left;
             TreeNode *right;
        result.push_back(root->val); // Visit current node
        inorder(root->left, result); // Traverse left subtree
        inorder(root->right, result); // Traverse right subtree
    }
};
