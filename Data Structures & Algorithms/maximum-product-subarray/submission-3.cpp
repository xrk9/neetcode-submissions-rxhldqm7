class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int globalMax = nums[0];
        int runningMax = nums[0];
        int runningMin = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] < 0) swap(runningMax, runningMin);
            runningMax = max(runningMax*nums[i], nums[i]);
            runningMin = min(runningMin*nums[i], nums[i]);
            globalMax = max(globalMax, runningMax);
        }
        return globalMax;
    }
};
