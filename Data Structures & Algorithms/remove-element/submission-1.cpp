class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int j = size - 1;
        for(int i = 0; i<=j; i++){
            if( nums[i] == val ){
                while( nums[j] == val && j > i ) j--;
                nums[i] = nums[j];
                nums[j] = val;
                j--;
            }
        }
        return j+1;
    }
};