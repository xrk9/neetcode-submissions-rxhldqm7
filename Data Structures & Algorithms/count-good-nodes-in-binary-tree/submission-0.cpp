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
private:
    void countGoodNodes(TreeNode* root, int& res){
        if(root->left){
            if(root->left->val >= root->val) ++res;
            else root->left->val = root->val;
            countGoodNodes(root->left,res);
        }
        if(root->right){
            if(root->right->val >= root->val) ++res;
            else root->right->val = root->val;
            countGoodNodes(root->right,res);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        int res = 1;
        countGoodNodes(root, res);
        return res;
    }
};
