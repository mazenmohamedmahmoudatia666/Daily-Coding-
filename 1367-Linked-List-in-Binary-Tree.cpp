class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;  // base case: tree is empty
        // Check if current node matches the head of the list, or search in left or right subtree
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) return true;   // linked list is fully matched
        if (!root) return false;  // tree is empty but linked list is not fully matched
        // Check if current values match and continue searching in both left and right subtrees
        if (root->val == head->val) {
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        }
        return false;  // no match at this node
    }
};
