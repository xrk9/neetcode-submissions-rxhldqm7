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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* start = head;
        ListNode* nxt = start;
        while(true){
            ListNode* end = start;
            for(int i = 0; i<k; i++){
                if(nxt) nxt=nxt->next;
                else{
                    curr->next = start;
                    return dummy->next;
                }
            }
            
            // reverse k nodes
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            for(int i = 0; i<k; i++){
                next = start->next;
                start->next = prev;
                prev = start;
                start = next;
            }

            curr->next = prev; 
            curr = end;
            start = nxt;

        }
        curr->next = start;
        return dummy->next;
    }
};
