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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> nums;
        TreeNode* Q[200];
        Q[0] = root; Q[1] = nullptr;
        int front = 0, rear = 1;
        int tmp = 0;
        while(true){
            TreeNode* node = Q[front++];
            if(node){
                tmp = node->val;
                if(node->left) Q[++rear] = node->left;
                if(node->right) Q[++rear] = node->right;
            }else{
                nums.push_back(tmp);
                if(Q[rear] == nullptr) return nums;
                Q[++rear] = nullptr;
            }
        }
    }
};
