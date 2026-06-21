class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        if (abs(target) > total_sum || ((total_sum + target) & 1) != 0) {
            return 0;
        }

        int amount = (total_sum + target) >> 1;
        
        vector<int> mem(amount + 1, 0);
        mem[0] = 1;
        
        for(const int& num : nums){
            for(int i = amount; i >= num; i--){
                mem[i] += mem[i - num];
            }
        }
        return mem[amount];
    }
};