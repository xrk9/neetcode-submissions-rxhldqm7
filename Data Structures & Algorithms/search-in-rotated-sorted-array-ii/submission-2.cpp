class Solution {
private:
    int bSearch(const vector<int>& nums, const int& target, int i, int j){
        while(i<=j){
            int m = (i+j)>>1;
            int res = target - nums[m];
            if(res > 0){
                i = ++m;
            } else if (res < 0) {
                j = --m;
            } else {
                return true;
            }
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        if(nums[i] < nums[j]) return bSearch(nums,target, i,j);
        while(i<=j){
            int m = (i+j)>>1;
            int val = nums[m];
            if(val == target || nums[j] == target || nums[i] == target){
                return true;
            }
            if(val == nums[i] && val == nums[j]){
                ++i;--j;
            } else if(val >= nums[i]){
                if(target < val && target > nums[i]) return bSearch(nums,target,i,--m);
                i = ++m;
            } else {
                if(target > val && target <= nums[j]) return bSearch(nums,target,++m,j);
                j = --m;               
            }
        }
        return false;
    }
};
