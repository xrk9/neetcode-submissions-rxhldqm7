class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> res;
        res.reserve(nums.size());
        for(int const& n:nums){
            res.insert(n);
        }
        int max = 0;
        for(int& n : nums){
            if(!res.contains(n-1)){
                int m = 0;
                while(res.contains(n++)) m++;
                m>max?max=m:1;
            }
        }
        return max;
    }
};
