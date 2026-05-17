class Solution {
private:
    vector<vector<int>> res;
    int n;
public:
    void recurse(vector<int>& nums, vector<int>& path, int s){
        if(s==n) res.emplace_back(path);
        else{
            path.emplace_back(nums[s]);
            recurse(nums, path, s+1);
            path.pop_back();
            recurse(nums, path, s+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> path;
        recurse(nums, path, 0);
        return res;
    }
};
