class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(const int& n : nums){
            counts[n]++;
        }
        vector<pair<int,int>> vec;
        for(const auto& [n, c] : counts){
            vec.emplace_back(c,n);
        }
        nth_element(vec.begin(), vec.begin() + k, vec.end(), greater<>());
        vector<int> res;
        for(int i = 0; i<k; i++){
            res.emplace_back(vec[i].second);
        }
        return res;
    }
};
