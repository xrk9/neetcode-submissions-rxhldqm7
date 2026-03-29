class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> myMap;
        for(string s:strs){
            map<char,int> m;
            for(char c:s) m[c]++;
            myMap[m].push_back(s);
        }
        vector<vector<string>> output;
        for(auto m:myMap){
            output.push_back(m.second);
        }
        return output;
    }
};
