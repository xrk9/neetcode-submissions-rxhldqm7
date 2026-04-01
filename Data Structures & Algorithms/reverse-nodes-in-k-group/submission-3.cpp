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
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* start = head;
        ListNode* next = head;
        while(true){
            for(int i = 1; i<k; i++){
                if(next) next = next->next;
                else{
                    curr->next = start;
                    return dummy->next;
                }
            }
            if(next){
                curr->next = next;
                next = next->next;
            }else{
                curr->next = start;
                return dummy->next;
            }
            curr = start;

            ListNode* prev = nullptr;
            ListNode* nx = nullptr;
            for(int i = 0; i<k; i++){
                nx = start->next;
                start->next = prev;
                prev = start;
                start = nx;
            }

            start = next;
        }
    }
};
