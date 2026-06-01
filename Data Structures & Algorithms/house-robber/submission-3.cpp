class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev_1 = nums[0];
        int prev_2 = 0;
        for(int i = 1; i<n; i++){
            int curr_max = max(nums[i] + prev_2, prev_1);

            prev_2 = prev_1;
            prev_1 = curr_max;
        }
        return prev_1;
        
    }
};
