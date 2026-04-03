/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> myMap;
        Node* dummy = new Node(0);
        Node* curr = dummy;
        Node* ptr = head;
        while(ptr){
            Node* tmp = new Node(ptr->val);
            curr->next = tmp;
            curr=curr->next;
            myMap[ptr] = tmp;
            ptr=ptr->next;
        }

        ptr = head;
        while(ptr){
            myMap[ptr]->random = myMap[ptr->random];
            ptr=ptr->next;
        }
        return dummy->next;
    }
};
