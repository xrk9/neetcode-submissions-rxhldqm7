class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n = nums.size();
        for(int i = 0; i<n-3; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j = i+1; j<n-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int l = j+1, r = n-1;
                while(r>l){
                    long long total = (long long)nums[i] + nums[j] + nums[r] + nums[l] - target;
                    if(total == 0){
                        output.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do{
                            ++l;
                        }while(l<n && nums[l] == nums[l-1]);
                        do{
                            --r;
                        }while(nums[r] == nums[r+1]);
                        continue;
                    }
                    if(total < 0){
                        do{
                            ++l;
                        }while(l<n && nums[l] == nums[l-1]);
                    } else {
                        do{
                            --r;
                        }while(nums[r] == nums[r+1]);
                    }
                }
            }
        }
        return output;
    }
};