class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(2*size);
        for(int i = 0; i<size; i++){
            output[i] = output[size + i] = nums[i];
        }
        return output;
    }
};