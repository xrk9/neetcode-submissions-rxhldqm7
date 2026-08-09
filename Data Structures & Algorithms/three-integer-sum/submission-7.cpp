class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        int curr = INT_MAX;
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            
            if (nums[i] == curr) continue;
            curr = nums[i];
            
            int l = i + 1, r = n - 1; 
            
            while (l < r) {
                int sum = nums[l] + nums[r] + curr;
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    res.push_back({curr, nums[l], nums[r]});
                    l++; 
                    r--;
                    
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};