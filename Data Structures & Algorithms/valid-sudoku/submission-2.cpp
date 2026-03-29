class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int chunk[9] = {0};
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.') continue;
                int bit = 1 << (board[r][c] - '1');
                int chunk_id = (r/3) * 3 + (c/3);

                if(row[r] & bit || col[c] & bit || chunk[chunk_id] & bit) return false;

                row[r] |= bit;
                col[c] |= bit;
                chunk[chunk_id] |= bit;
            }
        }
        return true;
    }
};
