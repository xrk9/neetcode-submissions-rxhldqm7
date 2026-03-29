class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> n = nums;
        int s = nums.size();
        k = k%s;
        int id = 0;
        for(int i = s-k; i<s; i++){
            nums[id++] = n[i];
        }
        for(int i = 0; id<s; i++){
            nums[id++] = n[i];
        }
    }
};