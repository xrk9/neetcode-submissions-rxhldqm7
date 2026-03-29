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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(head != nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* tmp = head;
        while(tmp!= nullptr && tmp->next!=nullptr){
            curr= curr->next;
            tmp=tmp->next->next;
        }
        tmp = curr->next;
        curr->next = nullptr;
        curr = reverseList(tmp);

        while(head && curr){
            tmp = head->next;
            head->next = curr;
            curr = curr->next;
            head->next->next = tmp;
            head = tmp;
        }
    }
};
