class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr;
        
        int sum = 0;
        vector<int> list; // Store sums of values between zeros

      //  ListNode* current = head->next; // Skip the initial zero node
        while (head->next) {
            if (head->next->val != 0) {
                sum += head->next->val;
            } else {
                list.push_back(sum);
                sum = 0;
            }
            head->next = head->next->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        for (int val : list) {
            result->next = new ListNode(val);
            result = result->next;
        }

        return dummy->next;
    }
};