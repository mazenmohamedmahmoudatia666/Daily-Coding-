class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(); // Dummy head for the result linked list
        ListNode* current = dummyHead; // Pointer to track the current node in the result list
        int carry = 0; // Initialize carry to 0

        // Iterate through both linked lists until both are exhausted
        while (l1 || l2 || carry) {
            int sum = carry; // Initialize sum with the carry value

            // Add the current digits from l1 and l2 (if available)
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry and compute the single digit result
            carry = sum / 10;
            int digit = sum % 10;

            // Create a new node with the single digit result and append it to the result list
            current->next = new ListNode(digit);
            current = current->next;
        }

        return dummyHead->next; // Return the next node after the dummy head as the head of the result list
    }
};
