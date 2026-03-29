class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> arr(3);
        for(int n:nums){
            arr[n]++;
        }
        int j = 0;
        for(int i = 0; i<3; i++){
            int n = arr[i];
            while(n--){
                nums[j++] = i;
            }
        }
    }
};