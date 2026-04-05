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
    bool isSim(TreeNode* A, TreeNode* B){
        if(!(A||B)) return true;
        if(!(A&&B)) return false;
        return (A->val == B->val) && isSim(A->left, B->left) && isSim(A->right, B->right);        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* qu[100];
        qu[0] = root;
        int front = 0, rear = 0;
        while(front<=rear){
            TreeNode* node = qu[front++];
            if(isSim(node, subRoot)) return true;
            if(node->left) qu[++rear] = node->left;
            if(node->right) qu[++rear] = node->right;
        }
        return false;
    }
};
