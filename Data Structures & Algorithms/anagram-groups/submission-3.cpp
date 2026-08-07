class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> at;

        for(const string& s : strs){
            string t = s;
            sort(t.begin(), t.end());

            if(auto it = at.find(t); it != at.end()) res[it->second].emplace_back(s);
            else{
                res.push_back({s});
                at.emplace(t, res.size() -1 );
            }
        }
        return res;
    }
};
