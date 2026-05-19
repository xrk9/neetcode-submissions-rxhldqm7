class Solution {
private:
    string s;
    int n;
    vector<string> res;
    vector<string> alphs = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void recurse(string path, int id){
        if(id == n) res.emplace_back(path);
        else{
            for(const char& c: alphs[s[id] - '2']){
                recurse(path+c, id+1);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        s = digits;
        n = digits.size();
        recurse("", 0);
        return res;
    }
};
