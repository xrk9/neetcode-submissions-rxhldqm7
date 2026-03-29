class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(n==1 || k == 0) return;
        int i = 0;
        int j = n - 1;
        while(i<j){
            swap(nums[i++], nums[j--]);
        }
        i = 0; j = k - 1;
        while(i<j){
            swap(nums[i++], nums[j--]);
        }
        i = k; j = n-1;
        while(i<j){
            swap(nums[i++], nums[j--]);
        }
    }
};