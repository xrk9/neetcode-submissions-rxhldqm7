class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> ar;
        int c = 0;
        ar[0]++;ar[nums[0]]++;
        (nums[0] == k) ? c++ : 1;
        for(int i = 1; i<n; i++){
            nums[i] = nums[i] + nums[i-1];
            c = c + ar[nums[i] - k];
            ar[nums[i]]++;
        }
        return c;
    }
};