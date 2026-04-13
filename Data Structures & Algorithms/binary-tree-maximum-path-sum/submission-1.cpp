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
    int helper(TreeNode* root, int& mx){
        if(!root) return 0;
        int l = max(0, helper(root->left, mx));
        int r = max(0, helper(root->right, mx));
        mx = max(mx, root->val + l + r);
        return root->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        helper(root,mx);
        return mx;
    }
};
