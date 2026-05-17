class Solution {
    vector<vector<int>> res;
    vector<int> path;
    int n;

    void recurse(const vector<int>& nums, int target, int id){
        if(target == 0){
            res.emplace_back(path);
            return;
        }
        for(int i = id; i<n; i++){
            int num = nums[i];
            if(i > id && num == nums[i-1]) continue;
            if(num > target) break;
            path.emplace_back(num);
            recurse(nums, target-num, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        recurse(nums, t, 0);
        return res;
    }
};
