class Solution {
private:
    string path;
    vector<string> res;
    void recurse(int open, int close){
        if(open == 0 && close == 0){
            res.emplace_back(path);
            return;
        }
        if(open > 0){
            path+='(';
            recurse(open-1, close);
            path.pop_back();
        }
        if(close > open){
            path+=')';
            recurse(open, close-1);
            path.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        recurse(n,n);
        return res;
    }
};
