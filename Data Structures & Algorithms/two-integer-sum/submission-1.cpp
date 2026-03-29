class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> myMap;

        int size = nums.size();

        for(int i = 0; i < size; i++){
            int t = target - nums[i];

            if(myMap.count(t)){
                vector<int> output = { myMap[t], i };
                return output;
            }

            else myMap[nums[i]] = i;
        }
    }
};
