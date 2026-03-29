class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, res;
        for(int num : nums){
            if(count == 0) res = num;

            if(num == res){
                count += 1;
            }else count -= 1;
        }
        return res;
    }
};