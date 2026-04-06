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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l,r;
        if(p->val > q->val){
            l = q->val;
            r = p->val;
        }else{
            r = q->val;
            l = p->val;
        }

        while(true){
            int val = root->val;
            if(val == l || val == r) return root;
            if(val > r) root = root->left;
            else if(val < l) root = root->right;
            else return root;
        }
    }
};
