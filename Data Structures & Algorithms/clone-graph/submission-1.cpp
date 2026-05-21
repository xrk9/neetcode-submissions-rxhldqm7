/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> hash;
    Node* dfs(Node* node){
        if(node == nullptr) return nullptr;
        if(hash.contains(node)) return hash[node];
        Node* newNode = new Node(node->val);
        hash[node] = newNode;
        for(Node* neighbor:node->neighbors){
            newNode->neighbors.emplace_back(dfs(neighbor));
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        Node* head = dfs(node);
        return head;
    }
};
