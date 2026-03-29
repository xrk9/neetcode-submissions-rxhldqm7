class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col[9][9] = {0};
        int chunk[3][3][9] = {0};
        for(int r = 0; r < 9; r++){
            int row[9] = {0};
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.') continue;
                int num = board[r][c] - '1';
                if(row[num]) return false;
                if(col[c][num]) return false;
                if(chunk[r/3][c/3][num]) return false;
                row[num] = 1;
                col[c][num] = 1;
                chunk[r/3][c/3][num] = 1;
            }
        }
        return true;
    }
};
