class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int max_len = 0;
        for(const auto& n : nums){
            if(seen.find(n-1)==seen.end()){
                int curr = n;
                int count = 1;
                while(seen.find(curr+1) != seen.end()){
                    curr++;
                    count++;
                }
                if(count > max_len) max_len = count;
            }
        }
        return max_len;
    }
};
