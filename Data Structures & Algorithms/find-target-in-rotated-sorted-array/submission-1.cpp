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
                return m;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        if(nums[i] <= nums[j]) return bSearch(nums,target, i,j);
        while(i<=j){
            int m = (i+j)>>1;
            int val = nums[m];
            if(val == target){
                return m;
            } else if(val >= nums[0]){
                if(target < val && target >= nums[i]) return bSearch(nums,target,i,m-1);
                i = ++m;
            } else {
                if(target > val && target <= nums[j]) return bSearch(nums,target,m+1,j);
                j = --m;               
            }
        }
        return -1;
    }
};
