class Solution {
public:
    void reorderList(ListNode* head) {


        //base Case
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;

        // traverse to the 2nd last node node of Linked list
        ListNode*prev_tail = head;
        while(prev_tail->next->next){
            prev_tail = prev_tail->next;
        }
        
        // 1->2->3->4->5->NULL
        prev_tail->next->next = head->next; // 1  2->3->4->5->2
        head->next = prev_tail->next;       // 1->5->2->3->4
        prev_tail->next = NULL;             // 1->5->2->3->4->NULL

        reorderList(head->next->next);
    }
};