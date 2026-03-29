class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n){
            int m = nums[0];
            for(int i = 1; i<n; i++){
                m = max(nums[i], m);
            }
            return {m};
        }
        vector<int> output;
        output.reserve(n-k+1);
        int l = 0, r = 0, L = 0;
        while((++r)<k){
            if(nums[r]>=nums[L]){
                L = r;
            };
        }
        output.push_back(nums[L]);
        while(r<n){
            if(L==l){
                L=l+1;
                for(int i = L+1; i<r; i++){
                    if(nums[i] >= nums[L]){
                        L=i;
                    }
                }
            }
            if(nums[r] >= nums[L]){
                L = r;
            }
            output.push_back(nums[L]);
            ++l,++r;
        }
        return output;
    }
};
