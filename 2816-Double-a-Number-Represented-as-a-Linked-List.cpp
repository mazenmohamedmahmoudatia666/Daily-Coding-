/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<int> s;
        
        // Push values of the linked list onto the stack
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
        
        ListNode* tail = nullptr;
        int res = 0;
        // Process each digit in the sum, starting from the least significant digit
        while (!s.empty() || res != 0) {
            tail = new ListNode(0, tail);
            if (!s.empty()) {
                res += s.top() * 2; // Double the digit and add the carry
                s.pop(); // Pop the used digit
            }
            tail->val = res % 10; // Store the least significant digit
            res /= 10; // Update the carry for the next iteration
        }

        return tail;
    }
};