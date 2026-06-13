class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if(n<m){
            swap(text1, text2);
            swap(n,m);
        }
        vector<int> dp(m+1, 0);
        for(int i = 0; i<n; i++){
            int diag = 0;
            for(int j = 0; j<m; j++){
                int tmp = dp[j+1];
                if(text1[i] == text2[j]) dp[j+1] = 1 + diag;
                else dp[j+1] = max(dp[j], dp[j+1]);
                diag = tmp;
            }
        }
        return dp[m];
    }
};
