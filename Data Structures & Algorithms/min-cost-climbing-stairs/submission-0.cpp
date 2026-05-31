class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> totalCost(n+1,0);
        for(int i = 2; i<=n; i++){
            totalCost[i] = min((cost[i-2] + totalCost[i-2]), (cost[i-1] + totalCost[i-1]));
        }
        return totalCost[n];
    }
};
