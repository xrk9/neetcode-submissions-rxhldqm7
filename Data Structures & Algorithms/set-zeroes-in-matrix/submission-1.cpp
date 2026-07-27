class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        bool col0 = false;

        for (int i = 0; i < nrow; i++) {
            if (matrix[i][0] == 0) col0 = true;
            
            for (int j = 1; j < ncol; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < nrow; i++) {
            for (int j = 1; j < ncol; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < ncol; j++) {
                matrix[0][j] = 0;
            }
        }

        if (col0) {
            for (int i = 0; i < nrow; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};