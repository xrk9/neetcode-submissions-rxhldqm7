class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(const int& num : nums) sum+=num;
        if(sum&1) return false;
        sum >>= 1;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for(const int& num : nums){
            if(num > sum) continue;
            for(int i = sum; i>=num; i--){
                if(dp[i-num]) dp[i] = 1;
            }
            if(dp[sum]) return true;
        }
        return dp[sum];
    }
};
