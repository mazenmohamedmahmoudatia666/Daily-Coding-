#include <vector>
#include <map>

using namespace std;

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a map to track the values that need to be deleted
       map<int,int>mp;
       for(auto&it : nums){
        mp[it]++;
       }

       if(nums.size() == 0)return 0;
        ListNode* dummy = new ListNode(0);

        dummy->next = head; // 1
        ListNode* prev = dummy;  // 0

        while(head){
            if(mp.find(head->val) != mp.end()){   // 1
            prev->next = head->next; // 2 
            delete head;
            head = prev->next;
           } else {
            prev = head;
            head = head->next;
            }

        }
        ListNode* newHead = dummy->next;
        delete dummy;;
        return newHead;

    }
};
