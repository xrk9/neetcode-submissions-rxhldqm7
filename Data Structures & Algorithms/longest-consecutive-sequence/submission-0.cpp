class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> res;
        for(int const& n:nums){
            res.insert(n);
        }
        int max = 0;
        for(int n : nums){
            if(!res.contains(n-1)){
                int m = 0;
                while(res.contains(n++)){
                    m++;
                }
                if(m>max) max = m;
            }
        }
        return max;
    }
};
