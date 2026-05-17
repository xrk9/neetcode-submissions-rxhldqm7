class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    int n;

    void recurse(vector<int>& nums, int target, int id){
        if(target == 0){
            res.emplace_back(path);
            return;
        }
        for(int i = id; i<n; i++){
            int num = nums[i];
            if(num > target) break;

            path.emplace_back(num);
            recurse(nums, target-num, i);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        recurse(nums, target, 0);
        return res;
    }
};
