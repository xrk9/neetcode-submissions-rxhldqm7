class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for(int i = 0; i<=m; i++){
            if(i==n-1) return true;
            m = max(m, i+nums[i]);
        }
        return false;
    }
};
