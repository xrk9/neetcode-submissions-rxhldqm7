class Solution {
private:
    int nrow, ncol;
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r<0 || c<0 || r>=nrow || c>=ncol || board[r][c] != 'O') return;
        board[r][c] = 'o';
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        nrow = board.size();
        ncol = board[0].size();
        for(int r = 0; r<nrow; r++){
            if(board[r][0] == 'O') dfs(board, r, 0);
            if(board[r][ncol-1] == 'O') dfs(board, r, ncol-1);
        }
        for(int c = 0; c<ncol; c++){
            if(board[0][c] == 'O') dfs(board, 0, c);
            if(board[nrow-1][c] == 'O') dfs(board, nrow-1, c);
        }
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                if(board[r][c] == 'o') board[r][c] = 'O';
                else if(board[r][c] == 'O') board[r][c] = 'X';
            }
        }
    }
};
