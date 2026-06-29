class Solution {
public:
    int solve(int l, int r, int leftBoundary, int rightBoundary, vector<int>& nums, vector<vector<int>>& dp) {
        if (l > r) return 0;

        int maxCoins = 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        for (int i = l; i <= r; i++) {
            int coins = leftBoundary * nums[i] * rightBoundary;
            maxCoins =
                max(maxCoins, coins + solve(l, i - 1, leftBoundary, nums[i], nums, dp) +
                                  solve(i + 1, r, nums[i], rightBoundary, nums, dp));
        }

        return dp[l][r] = maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(l, r, 1, 1, nums, dp);
    }
};