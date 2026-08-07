class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n);
        vector<int> s(n);
        int pp = 1, sp = 1;
        for(int i = 0; i<n; i++){
            p[i] = pp;
            pp*=nums[i];
        }
        for(int i = n-1; i>=0; i--){
            s[i] = sp;
            sp*=nums[i];
        }
        vector<int> res(n);
        for(int i = 0; i<n; i++){
            res[i] = p[i] * s[i];
        }
        return res;
    }
};
