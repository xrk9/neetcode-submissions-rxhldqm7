class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(const int& price : prices){
            if(price > buy) profit = max(profit, price-buy);
            else buy = price;
        }
        return profit;
    }
};
