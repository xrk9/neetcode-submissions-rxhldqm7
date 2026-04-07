/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        TreeNode* Q[1011];
        Q[0] = root; Q[1] = nullptr;
        int front = 0, rear = 1;
        while(true){
            TreeNode* node = Q[front++];
            if(node){
                tmp.push_back(node->val);
                if(node->left) Q[++rear] = node->left;
                if(node->right) Q[++rear] = node->right;
            }else{
                res.push_back(tmp);
                tmp.clear();
                if(Q[rear] == nullptr) break;
                Q[++rear] = nullptr;
            }
        }
        return res;
    }
};
