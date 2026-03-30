class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int val = nums[abs(nums[i]) - 1];
            if(val > 0){
                nums[abs(nums[i]) - 1] = -val;
            }else{
                return abs(nums[i]);
            }
        }
    }
};
