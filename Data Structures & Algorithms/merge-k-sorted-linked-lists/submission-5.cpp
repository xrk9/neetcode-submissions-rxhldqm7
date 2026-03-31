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

    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for(ListNode* node:lists){
            if(node) minHeap.push(node);
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(!minHeap.empty()){
            ListNode* min = minHeap.top();
            curr->next = min;
            minHeap.pop();
            curr = curr->next;
            
            if(min->next){
                minHeap.push(min->next);
            }

        }
        return dummy->next;
    }
};
