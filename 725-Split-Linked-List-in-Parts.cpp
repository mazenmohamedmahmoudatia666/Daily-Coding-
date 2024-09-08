class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* node = head;
        int cnt = 0;
        
        // Count the total number of nodes
        while (node) {
            node = node->next;
            cnt++;
        }
        
        // Calculate the number of nodes per part and the remainder
        int div = cnt / k;  // 10 / 3 = 3
        int rem = cnt % k;  // 10 % 3  = 1
        
        vector<ListNode*> result;
        ListNode* current = head;
        
        for (int i = 0; i < k; i++) {
             //             3
            ListNode* partHead = current;  // 1
            ListNode* partTail = nullptr;  // 4
            
            // Determine the size of the current part
            int partSize = div + (i < rem ? 1 : 0);  // 4
            
            // Traverse the list to the end of the current part
            for (int j = 0; j < partSize; j++) {
                partTail = current;
                if (current) current = current->next;
            }
            
            // Disconnect the part from the rest of the list
            if (partTail) partTail->next = nullptr;
            
            result.push_back(partHead);
        }
        
        return result;
    }
};
