class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        int sum = numbers[l] + numbers[r];
        while(l<r){
            if(sum==target) return {l+1, r+1};
            (sum<target) ? (sum=sum-numbers[l]+numbers[++l]) : (sum=sum-numbers[r]+numbers[--r]);
        }
        return {l+1, r+1};
    }
};
