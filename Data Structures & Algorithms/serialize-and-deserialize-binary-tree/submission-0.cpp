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

class Codec {
private:
    void serializeHelper(TreeNode* root, string& s){
        if(!root){
            int val = -1001;
            s.append(reinterpret_cast<const char*>(&val), sizeof(int));
            return;
        }
        s.append(reinterpret_cast<const char*>(&(root->val)), sizeof(int));
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(const int*& p){
        int val = *p++;
        if(val == -1001) return nullptr;
        TreeNode* root = new TreeNode(val);
        root->left = deserializeHelper(p);
        root->right = deserializeHelper(p);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        const int* p = reinterpret_cast<const int*>(data.data());
        return deserializeHelper(p);
    }
};
