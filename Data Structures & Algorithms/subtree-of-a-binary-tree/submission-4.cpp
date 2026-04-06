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

    uint32_t hash(uint32_t x){
        return ((x<<16)^x)*1000000007;
    }

    bool check(int* main, int* sub, int index, int cap){
        for(int i = 0; i<cap; i++){
            if(sub[i] != main[index++]) return false;
        }
        return true;
    }

    void parse(TreeNode* root, int* arr, int& index){
        if(root == nullptr){
            arr[index++] = -101;
            return;
        }
        arr[index++] = root->val;
        parse(root->left, arr, index);
        parse(root->right, arr, index);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int mainArr[100]; int capacity = 0;
        int subArr[100]; int subCap = 0;
        parse(root, mainArr, capacity);
        parse(subRoot, subArr, subCap);

        uint32_t myHash = 0;
        uint32_t runningHash = 0;
        uint32_t c = 1;
        for(int i = subCap - 1; i>=0; --i){
            c*=1000000009;
            myHash += (hash((uint32_t)subArr[i]) * c);
            runningHash += (hash((uint32_t)mainArr[i]) * c);
        }

        mainArr[capacity] = 101;
        for(int j = subCap; j<=capacity; ++j){
            if(runningHash == myHash && check(mainArr, subArr, j - subCap, subCap)){
                return true;
            }else{
                runningHash -= hash((uint32_t)mainArr[j-subCap]) * c;
                runningHash *= 1000000009;
                runningHash += hash((uint32_t)mainArr[j]) * 1000000009;
            }
        }
        return false;
    }
};
