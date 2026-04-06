class Solution {
private:
    const uint32_t P = 1000000009;
    const uint32_t S = 1000000007;

    uint32_t hash(int x) {
        uint32_t val = static_cast<uint32_t>(x);
        return ((val << 16) ^ val) * S;
    }

    void parse(TreeNode* root, vector<int>& arr) {
        if (!root) {
            arr.push_back(-1001);
            return;
        }
        arr.push_back(root->val);
        parse(root->left, arr);
        parse(root->right, arr);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> mainArr, subArr;
        parse(root, mainArr);
        parse(subRoot, subArr);

        int n = mainArr.size();
        int m = subArr.size();
        if (m > n) return false;

        uint32_t targetHash = 0;
        uint32_t currentHash = 0;
        uint32_t c = 1;

        for (int i = 0; i < m; i++) {
            targetHash = targetHash * P + hash(subArr[i]);
            currentHash = currentHash * P + hash(mainArr[i]);
            if (i < m - 1) c *= P;
        }

        for (int i = 0; i <= n - m; i++) {
            if (currentHash == targetHash) {
                bool isSub = true;
                for (int j = 0; j < m; j++) {
                    if (mainArr[i + j] != subArr[j]) {
                        isSub = false;
                        break;
                    }
                }
                if (isSub) return true;
            }

            if (i < n - m) {
                currentHash -= hash(mainArr[i]) * c;
                currentHash = currentHash * P + hash(mainArr[i + m]);
            }
        }

        return false;
    }
};