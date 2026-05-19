class Solution {
private:
    bool isPal(string_view s){
        if(s.size() == 1) return true;
        int i = 0, j = s.size() - 1;
        while(i<j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int n;
    string s;
    vector<string> p;
    vector<vector<string>> res;
    void recurse(int id){
        if(id == n){
            res.emplace_back(p);
            return;
        }
        for(int l = 1; l<=n-id; l++){
            auto sub = string_view(s).substr(id,l);
            if(isPal(sub)){
                p.emplace_back(sub);
                recurse(id+l);
                p.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string k) {
        n = k.size();
        s = k;
        recurse(0);
        return res;
    }
};
