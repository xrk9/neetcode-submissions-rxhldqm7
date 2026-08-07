class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> myMap;
        vector<vector<string>> res;
        int index = 0;
        int n = strs.size();
        for(int i = 0; i<n; i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            if(!myMap.contains(str)){
                myMap[str] = index++;
                res.push_back(vector<string>{strs[i]});
            }
            else res[myMap[str]].emplace_back(strs[i]);
        }
        return res;
    }
};
