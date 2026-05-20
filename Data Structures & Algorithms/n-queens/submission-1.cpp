class Solution {
private:
    int n;
    char col[8] = {0};  // col number
    char pDia[15] = {0};    // positive diagonal {{(0,0)}, {(0,1), (1,0)}, {(0,2), (1,1), (2,0)}, ...} sum of row and col as 0,1,2,..., find pDia by (row+col)
    char nDia[15] = {0};    // negative diagonal {{(0,0)}, {(0,1), (1,0)}, {(0,2), (1,1), (2,0)}, ...} difference of col-row as ....-2,-1,0,1,2... (from bottm left to top right) find nDia by (c-r+7)

    vector<vector<string>> res;
    vector<string> path;
    void recurse(int r){
        if(r == n){
            res.emplace_back(path);
            return;
        }
        for(int c = 0; c<n; c++){
            if(col[c] || pDia[r+c] || nDia[c-r+7]) continue;
            path[r][c] = 'Q';
            col[c] = 1;
            pDia[r+c] = 1;
            nDia[c-r+7] = 1;
            recurse(r+1);
            path[r][c] = '.';
            col[c] = 0;
            pDia[r+c] = 0;
            nDia[c-r+7] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int k) {
        n = k;
        for(int i = 0; i<k; i++){
            string s;
            for(int j = 0; j<k; j++){
                s+='.';
            }
            path.emplace_back(s);
        }
        recurse(0);
        return res;
    }
};
