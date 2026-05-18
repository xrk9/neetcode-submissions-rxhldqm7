class Solution {
    int nrow, ncol, n;
    string word;
    bool recurse(vector<vector<char>>& board, int id, int r, int c){
        if(id == n) return true;
        // top
        if(r-1 >= 0 && board[r-1][c] == word[id]){
            board[r-1][c] = 0;
            if(recurse(board, id+1, r-1, c)) return true;
            board[r-1][c] = word[id];
        }
        // bottom
        if(r+1 < nrow && board[r+1][c] == word[id]){
            board[r+1][c] = 0;
            if(recurse(board, id+1, r+1, c)) return true;
            board[r+1][c] = word[id];
        }
        // left
        if(c-1 >= 0 && board[r][c-1] == word[id]){
            board[r][c-1] = 0;
            if(recurse(board, id+1, r, c-1)) return true;
            board[r][c-1] = word[id];
        }
        // right
        if(c+1 < ncol && board[r][c+1] == word[id]){
            board[r][c+1] = 0;
            if(recurse(board, id+1, r, c+1)) return true;
            board[r][c+1] = word[id];
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string w) {
        nrow = board.size(); ncol = board[0].size(); n = w.size();
        word = w;
        for(int i = 0; i<nrow; i++){
            for(int j = 0; j<ncol; j++){
                if(board[i][j] == w[0]){
                    board[i][j] = 0;
                    if(recurse(board, 1, i, j)) return true;
                    board[i][j] = w[0];
                }
            }
        }
        return false;
    }
};
