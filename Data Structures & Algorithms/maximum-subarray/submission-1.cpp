class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int curr = 0;
        for(const int& num : nums){
            curr+=num;
            mx = max(mx, curr);
            if(curr<0) curr = 0;
        }
        return mx;
    }
};
