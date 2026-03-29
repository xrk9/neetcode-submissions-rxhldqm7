class NumMatrix {
private:
    vector<vector<int>> ourMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        for(vector<int>& vec:matrix){
            for(int x = 1; x<col; x++){
                vec[x] += vec[x-1];
            }
        }

        for(int r = 1; r < row; r++){
            for(int c = 0; c < col; c++){
                matrix[r][c] += matrix[r-1][c];
            }
        }

        ourMatrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int fullSum = ourMatrix[row2][col2];
        int left = col1 - 1;
        int top = row1 - 1;
        if(left >= 0 && top >= 0){
            return fullSum - ourMatrix[top][col2] - ourMatrix[row2][left] + ourMatrix[top][left];
        }else if(left >= 0){
            return fullSum - ourMatrix[row2][left];
        }else if(top >= 0){
            return fullSum - ourMatrix[top][col2];
        }else return fullSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */