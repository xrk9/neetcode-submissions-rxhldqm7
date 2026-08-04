class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))>>1;
        int r_sum = 0;
        for(const int& num : nums) r_sum += num;
        return sum - r_sum;
    }
};
