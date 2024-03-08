class Solution {
public:
    void reverse (ListNode *&head, ListNode *&curr, ListNode *&prev)
    {
        // base case 
        if(curr==NULL)
        {
            head = prev;
            return;
        }

        // solve the problem for the first node and then use recursion
        ListNode *forward = curr -> next ; 
        curr -> next = prev;
        reverse(head, forward, curr);
    }
    ListNode* reverseList(ListNode* head) {
        // recursive solution 
        // ListNode *forward= NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;

        reverse(head, curr, prev);
        return head;
    }
};