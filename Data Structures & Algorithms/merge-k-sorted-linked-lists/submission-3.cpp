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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(true){
            ListNode* min = nullptr;
            int indx = -1;
            for(int i = 0; i<n; i++){
                ListNode* node = lists[i];
                if(node && (min == nullptr || node->val < min->val)){
                    min = node;
                    indx = i;
                }
            }
            if(indx == -1) break;
            curr->next = lists[indx];
            curr=curr->next;
            lists[indx] = lists[indx]->next;

        }
        return dummy->next;
    }
};
