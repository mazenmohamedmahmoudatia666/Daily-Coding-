#include <iostream>
using namespace std;

// Definition for singly-linked list.

// Function to compute GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b; // 6
        b = a % b; // 18 % 6 = 0
        a = temp; // 6
    }
    return a; // 6
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;  // If the list is empty or has only one node, return as is
        }

        ListNode* current = head;

        while (current && current->next) {
            int divisor = gcd(current->val, current->next->val);
            ListNode* newNode = new ListNode(divisor);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;  // Move to the next pair of nodes
        }

        return head;
    }
};
