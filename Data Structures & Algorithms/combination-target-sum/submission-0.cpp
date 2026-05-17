class Solution {
private:
    vector<vector<int>> res;
    int target;
    int sum = 0;
    int max;
public:
    void recurse(vector<int>& nums, vector<int>& path, int id){
        if(sum == target) res.emplace_back(path);
        else if(sum > target || id==max) return;
        else{
            path.emplace_back(nums[id]);
            sum+=nums[id];
            recurse(nums, path, id);

            path.pop_back();
            sum-=nums[id];
            recurse(nums, path, id+1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int ta) {
        target = ta;
        max = nums.size();
        vector<int> path;
        recurse(nums, path, 0);
        return res;
    }
};
