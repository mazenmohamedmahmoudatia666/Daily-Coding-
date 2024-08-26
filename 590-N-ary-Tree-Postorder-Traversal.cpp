/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};  // If the root is null, return an empty list
        
        vector<int> result;
        stack<Node*> st;
        st.push(root);
        
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            
            result.push_back(node->val);  // Add the node value to the result
            
            // Push all children onto the stack
            for (Node* child : node->children) {
                st.push(child);
            }
        }
        
        // Since we're simulating postorder traversal in reverse order, we need to reverse the result.
        reverse(result.begin(), result.end());
        
        return result;
    }
};