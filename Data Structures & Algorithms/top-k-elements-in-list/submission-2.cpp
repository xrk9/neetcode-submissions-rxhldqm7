class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        int n = nums.size();
        unordered_map<int,int> m;
        for(int const& n:nums){
            m[n]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto const& [a,b]:m){
            bucket[b].push_back(a);
        }
        for(int i = n;;i--){
            for(int const& num:bucket[i]){
                output.push_back(num);
            }
            if(output.size() == k) break;
        }
        return output;
    }
};
