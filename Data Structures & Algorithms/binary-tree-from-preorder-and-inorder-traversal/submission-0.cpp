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
    TreeNode* buildNode(const vector<int>& preorder, int low, int high, const vector<int>& inorder, int& index, const unordered_map<int,int>& order){
        if(low>high) return nullptr;
        TreeNode* root = new TreeNode(preorder[index]);
        int id = order.at(preorder[index++]);
        root->left = buildNode(preorder, low, id-1, inorder, index, order);
        root->right = buildNode(preorder, id+1, high, inorder, index, order);
        return root;
    }
public:
    TreeNode* buildTree(const vector<int>& preorder,const vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> order;
        for(int i = 0; i<n; i++){
            order[inorder[i]] = i;
        }
        int index = 0;
        return buildNode(preorder, 0, n-1, inorder, index, order);
    }
};
