class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix.size()-1;
        while(i<=j){
            int m = (i+j)/2;
            int res = target - matrix[m][0];
            if(res > 0){
                i = ++m;
            } else if (res < 0) {
                j = --m;
            } else {
                return true;
            }
        }
        if(j<0) return false;

        i = 0;
        int k = matrix[0].size()-1;
        while(i<=k){
            int m = (i+k)/2;
            int res = target - matrix[j][m];
            if(res > 0){
                i = ++m;
            } else if (res < 0) {
                k = --m;
            } else {
                return true;
            }
        }
        return false;
    }
};
