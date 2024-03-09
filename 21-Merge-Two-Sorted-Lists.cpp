class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (l1 && l2) {
            ListNode* newNode = nullptr;
            if (l1->val <= l2->val) {
                newNode = l1;
                l1 = l1->next;
            } else {
                newNode = l2;
                l2 = l2->next;
            }
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return head;
    }
};
