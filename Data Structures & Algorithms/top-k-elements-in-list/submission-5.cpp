class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(const auto& n : nums){
            counts[n]++;
        }
        int n = nums.size();
        vector<vector<int>> vec(n+1, vector<int>());
        for(const auto& [n, c] : counts){
            vec[c].emplace_back(n);
        }
        vector<int> res;
        for(int i = n; i>=0 && res.size() < k; i--){
            if(vec[i].size() == 0) continue;
            for(const int& num : vec[i]) res.emplace_back(num);
        }
        return res;
    }
};
