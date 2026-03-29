class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int arr[4] = {0};
        for(int const& k:nums){
            (arr[2]) ? ((arr[3]) ? 1 : (arr[1] = k)) : (arr[0] = k);
            (k==arr[0]) ? (arr[2]++) : ((k==arr[1]) ? (arr[3]++) : (arr[2]--,arr[3]--));
        }
        vector<int> output;
        int m = nums.size()/3;
        arr[2] = arr[3] = 0;
        for(int const& k:nums){
            (k==arr[0]) ? (arr[2]++) : ((k==arr[1]) ? (arr[3]++) : 1);
        }
        (arr[2] > m) ? output.push_back(arr[0]) : void();
        (arr[3] > m) ? output.push_back(arr[1]) : void();
        return output;
    }
};