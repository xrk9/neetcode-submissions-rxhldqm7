class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        switch(n){
            case 1 :
                return nums[0];
            case 2:
                return max(nums[0], nums[1]);
            case 3:
                return max(nums[0] + nums[2], nums[1]);
        }
        vector<int> loot(n);
        loot[0] = nums[0];
        loot[1] = nums[1];
        loot[2] = nums[2] + nums[0];
        for(int i = 3; i<n; i++){
            loot[i] = nums[i] + max(loot[i-2], loot[i-3]);
        }
        return max(loot[n-1], loot[n-2]);
    }
};
