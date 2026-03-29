class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i<=j){
            int m = (i+j)/2;
            int res = target - nums[m];
            if(res == 0){
                return m;
            } else if (res > 0) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return -1;
    }
};
