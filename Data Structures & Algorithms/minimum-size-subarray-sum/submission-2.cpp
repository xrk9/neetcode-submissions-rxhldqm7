class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int r = -1, l = -1;
        int len = INT_MAX;
        int sum = 0;
        while((r+1)<n){
            while(++r < n && sum < target){
                sum+=nums[r];
            }
            if(r==n && sum<target) break;
            --r;
            while(sum >= target){
                sum-=nums[++l];
            }
            int lt = r-l+1;
            if(lt<len){
                len = lt;
            }
            
        }
        if(len==INT_MAX){
            return 0;
        }
        return len;
    }
};