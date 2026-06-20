class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> mem(amount+1);
        mem[0] = 1;
        for(const int& coin : coins){
            for(int i = 1; i<= amount; i++){
                mem[i] += ((i-coin >= 0) ? mem[i-coin] : 0);
            }
        }
        return mem[amount];
    }
};
