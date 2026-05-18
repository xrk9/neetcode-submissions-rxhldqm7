class Solution {
private:
    vector<vector<int>> res;
    int n;

    void recurse(vector<int>& nums, int id){
        if(id == n){
            res.emplace_back(nums);
            return;
        }
        for(int i = id; i<n; i++){
            swap(nums[i], nums[id]);
            recurse(nums, id+1);
            swap(nums[i], nums[id]);
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        recurse(nums, 0);
        return res;
    }
};
