class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(size, 1);

        for(int i = 1; i<size; i++){
            output[i] = output[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int i = size - 1; i>0; i--){
            suffix *= nums[i];
            output[i-1] *= suffix;
        }
        
        return output;

    }
};
