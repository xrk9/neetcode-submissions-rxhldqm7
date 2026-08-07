class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int pp = 1;
        for(int i = 0; i < n; i++) {
            res[i] = pp;
            pp *= nums[i];
        }
        
        int sp = 1;
        for(int i = n - 1; i >= 0; i--) {
            res[i] *= sp;
            sp *= nums[i];
        }
        
        return res;
    }
};