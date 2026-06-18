class Solution {
private:
    int n;
    vector<int>* Prices;
    unordered_map<int,int> dp;
    int dfs(int i, bool buying){
        if(i >= n) return 0;
        int key = (i<<1) | buying;
        if(dp.contains(key)) return dp[key];
        int cooldown = dfs(i+1, buying);
        int profit;
        if(buying){
            profit = dfs(i+1, !buying) - (*Prices)[i];
        }else{
            profit = dfs(i+2, !buying) + (*Prices)[i];
        }
        dp[key] = max(profit, cooldown);
        return dp[key];
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        Prices = &prices;
        return dfs(0, 1);
    }
};
