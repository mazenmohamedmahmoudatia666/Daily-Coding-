/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* invert(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        
        TreeNode* left = invert(root->right); // Invert the left subtree
        TreeNode* right = invert(root->left); // Invert the right subtree
        
        root->left = left; // Swap left and right subtrees
        root->right = right;
        
        return root; // Return the root of the inverted subtree
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
