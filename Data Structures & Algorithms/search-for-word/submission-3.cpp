class Solution {
    int nrow, ncol, n;
    string word;
    bool recurse(vector<vector<char>>& board, int id, int r, int c){
        if(id == n) return true;
        if(r < 0 || r >= nrow || c < 0 || c >= ncol || id > n || board[r][c] != word[id]) return false;
        board[r][c] = '#';
        if( recurse(board, id+1, r-1, c) ||
            recurse(board, id+1, r+1, c) ||
            recurse(board, id+1, r, c-1) ||
            recurse(board, id+1, r, c+1) ) return true;
        board[r][c] = word[id];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string w) {
        nrow = board.size(); ncol = board[0].size(); n = w.size();
        word = w;
        for(int i =0; i<nrow; i++){
            for(int j = 0; j<ncol; j++){
                if(board[i][j] == word[0]){
                    if(recurse(board, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};
