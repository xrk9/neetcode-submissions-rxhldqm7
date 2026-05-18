class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> chosen;
    int n;

    void recurse(const vector<int>& nums){
        if(path.size() == n){
            res.emplace_back(path);
            return;
        }
        for(int i = 0; i<n; i++){
            if(!chosen[i]){
                chosen[i] = 1;
                path.emplace_back(nums[i]);
                recurse(nums);
                chosen[i] = 0;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        chosen.assign(n,0);
        recurse(nums);
        return res;
    }
};
