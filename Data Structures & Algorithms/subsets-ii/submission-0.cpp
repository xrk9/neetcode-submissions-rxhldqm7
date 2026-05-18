class Solution {
private: 
    int n;
    vector<vector<int>> res;
    vector<int> path;
    void recurse(const vector<int>& nums, int id){
        res.emplace_back(path);
        for(int i = id; i<n; i++){
            if(i>id && nums[i] == nums[i-1]) continue;
            path.emplace_back(nums[i]);
            recurse(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        recurse(nums,0);
        return res;
    }
};
