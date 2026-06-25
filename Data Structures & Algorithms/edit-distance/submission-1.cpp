class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i == word1.length() || j == word2.length()) {
            return word1.length() + word2.length() - i - j;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
        } else {
            return dp[i][j] =
                       1 + min(solve(i + 1, j, word1, word2, dp),
                               min(solve(i, j + 1, word1, word2, dp),
                                   solve(i + 1, j + 1, word1, word2, dp)));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        return solve(0, 0, word1, word2, dp);
    }
};