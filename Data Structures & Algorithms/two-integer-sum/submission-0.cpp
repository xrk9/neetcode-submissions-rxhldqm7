class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output(2);
        unordered_set<int> mySet;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(mySet.count(target - nums[i])){
                for(int j = 0 ;; j++){
                    if(nums[j] == (target - nums[i])){
                        output[0] = j;
                        output[1] = i;
                        return output;
                    }
                }
            }
            else mySet.insert(nums[i]);
        }
    }
};
