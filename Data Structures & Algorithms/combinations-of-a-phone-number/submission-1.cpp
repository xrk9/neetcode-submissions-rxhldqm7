class Solution {
private:
    string s;
    int n;
    vector<string> res;
    vector<string> alphs = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string path;

    void recurse(int id){
        if(id == n) res.emplace_back(path);
        else{
            for(const char& c: alphs[s[id] - '2']){
                path+=c;
                recurse(id+1);
                path.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        s = digits;
        n = digits.size();
        recurse(0);
        return res;
    }
};
