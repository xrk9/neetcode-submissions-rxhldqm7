class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0, c1 = 0, c2 = 0;
        for(int const& n:nums){
            c1 ? (c2 ? 1 : (num2 = n)) : (num1 = n) ;
            (n == num1) ? (c1++) : ((n==num2) ? (c2++) : (c1--,c2--));
        }
        c1=c2=0;
        for(int const& n:nums){
            (n==num1) ? (c1++) :((n==num2) ? (c2++) : 1);
        }
        vector<int> output;
        int m = nums.size()/3;
        (c1>m) ? (output.push_back(num1)) : void();
        (c2>m) ? (output.push_back(num2)) : void();
        return output;
    }
};