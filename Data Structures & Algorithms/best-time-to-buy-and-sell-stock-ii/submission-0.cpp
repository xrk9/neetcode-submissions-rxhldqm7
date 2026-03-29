class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        int profit = 0;
        for(int i = 1; i<s; i++){
            int t = (prices[i] - prices[i-1]);
            (t > 0) ? profit+=t : 1;
        }
        return profit;
    }
};