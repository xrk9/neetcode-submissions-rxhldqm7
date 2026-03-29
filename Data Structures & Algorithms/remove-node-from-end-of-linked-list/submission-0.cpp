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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx = 0;
        ListNode* curr = head;
        while(head){
            ++idx;
            head = head->next;
        }
        head = curr;
        idx -= n;
        if(idx == 0){
            curr = curr->next;
            return curr;
        }
        while(--idx){
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};
