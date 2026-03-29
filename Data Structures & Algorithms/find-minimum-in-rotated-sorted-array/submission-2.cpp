class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        if(nums[i] <= nums[j]) return nums[i];
        while(i<=j){
            int m = (i+j)>>1;
            if(nums[m]>=nums[0]){
                i = ++m;
            } else {
                j = --m;                
            }
        }
        return nums[i];
    }
};