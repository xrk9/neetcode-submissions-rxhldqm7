class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        queue<int> q;
        unordered_set<long> s;
        q.emplace(0);
        int h = 0;
        while(!q.empty()){
            ++h;
            for(int i = q.size(); i>0; i--){
                int prev = q.front(); q.pop();
                for(const int& coin : coins){
                    long curr = (long)prev + coin;
                    if(curr > amount || s.count(curr)) continue;
                    if(curr == amount) return h;
                    s.insert(curr);
                    q.emplace(curr);
                }
            }
        }
        return -1;
    }
};
