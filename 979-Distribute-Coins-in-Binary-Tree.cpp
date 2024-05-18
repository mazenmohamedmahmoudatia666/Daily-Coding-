class Solution {
public:
    int moves = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left_excess = dfs(node->left);
        int right_excess = dfs(node->right);
        moves += abs(left_excess) + abs(right_excess);
        return node->val + left_excess + right_excess - 1;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};