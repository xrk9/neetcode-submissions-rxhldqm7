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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int h = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        q.push(nullptr);
        while(true){
            while(q.front() != nullptr){
                TreeNode* top = q.front();
                q.pop();
                if(top->left) q.emplace(top->left);
                if(top->right) q.emplace(top->right);
            }
            q.pop();
            ++h;                                                                                                           
            if(q.empty()) break;
            q.push(nullptr);
        }
        return h;
    }
};
