class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        int profit = 0;
        int i = 0;
        int min = prices[0];
        while(++i<n){
            int p = prices[i] - min;
            if(p>profit){
                profit = p;
            } else if (prices[i] < min){
                min = prices[i];
            }
        }
        return profit;
    }
};
