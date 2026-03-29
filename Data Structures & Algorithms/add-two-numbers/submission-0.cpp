class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int carry = 0;

        while (l1 || l2 || carry ) {
            int sum = carry;
            
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = (sum>9) ? 1 : 0;
            sum = carry ? (sum - 10) : sum;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }

        return head->next;
    }
};