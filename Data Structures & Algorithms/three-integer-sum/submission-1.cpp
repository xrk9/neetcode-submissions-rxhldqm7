class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n-2; i++){
            while(i>0 && i<n && (nums[i] == nums[i-1])) ++i;
            int l = i+1, r=n-1;
            while(r>l){
                int total = nums[i] + nums[l] + nums[r];
                if(total == 0){
                    output.push_back({nums[i], nums[l], nums[r]});
                }
                if (total < 0){
                    do{
                        ++l;
                    }while(l<n && nums[l] == nums[l-1]);
                } else {
                    do{
                        --r;
                    }while(r<n && nums[r] == nums[r+1]);
                }
            }
        }
        return output;
    }
};
