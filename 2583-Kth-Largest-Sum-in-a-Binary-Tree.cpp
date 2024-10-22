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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        // Initialize a queue for BFS
        queue<TreeNode*> q;
        q.push(root);

        // Vector to store level sums
        vector<long long> levelSums;

        // BFS loop
        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;  // Accumulate sum for the current level

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // Get node at the front of the queue
                q.pop();

                levelSum += node->val;  // Add node's value to the level sum

                // Push children of the current node to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Store the sum of this level
            levelSums.push_back(levelSum);
        }

        // Sort the level sums in descending order
        sort(levelSums.rbegin(), levelSums.rend());

        // Return the k-th largest sum if k is valid
        if (k <= levelSums.size()) {
            return levelSums[k - 1];
        } else {
            return -1;  // Return -1 if k is out of range
        }
    }
};
