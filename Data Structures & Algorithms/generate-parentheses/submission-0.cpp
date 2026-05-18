class Solution {
private:
    int n;
    int nO; int nC = 0;
    string path;
    vector<string> res;

    void recurse(){
        if(nO){
            path += '(';
            nO--; nC++;
            recurse();
            path.pop_back();
            nO++; nC--;
        }
        if(nC){
            path+=')';
            nC--;
            recurse();
            path.pop_back();
            nC++;
        }
        if(nO == 0 && nC == 0){
            res.emplace_back(path);
        }
    }
public:
    vector<string> generateParenthesis(int s) {
        n = s;
        nO = s;
        recurse();
        return res;
    }
};
