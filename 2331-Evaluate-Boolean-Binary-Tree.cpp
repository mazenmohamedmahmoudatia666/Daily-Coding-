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
public:
    bool evaluateTree(TreeNode* root) {
        // If the node is a leaf node
        if (!root->left && !root->right) {
            return root->val == 1;
        }
        
        // Evaluate left and right subtrees
        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        // Apply the operator at the current node
        if (root->val == 2) { // OR operator
            return leftVal || rightVal;
        } else if (root->val == 3) { // AND operator
            return leftVal && rightVal;
        }

        // If the value is not 0, 1, 2, or 3, it is an invalid tree node value for this problem
        return false;
    }
};
