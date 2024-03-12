class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast pointer 'n' steps ahead
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        // Handle special case: deletion of head node
        if(fast == NULL){
            ListNode *ans = head->next;
            delete(head);
            return ans;
        }

        // Move both pointers until fast reaches the end
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node from the end
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;

        // Delete the node
        delete(delNode);

        // Return the head of modified list
        return head;
    }
};