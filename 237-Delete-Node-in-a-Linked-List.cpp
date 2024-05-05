class Solution
{
public:
    // Function to delete a node from a singly linked list
    void deleteNode(ListNode *node)
    {
        // Traverse the list until the second last node
        while (node->next->next)
        {
            // Copy the value of the next node to the current node
            node->val = node->next->val;
            // Move to the next node
            node = node->next;
        }
        // Copy the value of the last node to the current node
        node->val = node->next->val;
        // Remove the last node by setting the next pointer to NULL
        node->next = NULL;
    }
};