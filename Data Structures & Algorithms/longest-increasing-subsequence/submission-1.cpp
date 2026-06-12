class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> mem(n,1);
        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(nums[j] < nums[i]) mem[i] = max(mem[i], mem[j]+1);
            }
        }
        int longest = 1;
        for(int i = 1; i<n; i++){
            if(mem[i] > longest) longest = mem[i];
        }
        return longest;
    }
};
