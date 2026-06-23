class Solution {
private:
    int nrow, ncol;
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& mem) {
        if (mem[r][c] != -1) return mem[r][c];

        int max_len = 1;

        for (const auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            if (nr >= 0 && nr < nrow && nc >= 0 && nc < ncol && matrix[nr][nc] > matrix[r][c]) {
                int len = 1 + dfs(nr, nc, matrix, mem);
                max_len = max(max_len, len);
            }
        }

        return mem[r][c] = max_len;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        nrow = matrix.size(); 
        ncol = matrix[0].size();
        
        vector<vector<int>> mem(nrow, vector<int>(ncol, -1));
        int longest_path = 0;

        for (int r = 0; r < nrow; r++) {
            for (int c = 0; c < ncol; c++) {
                longest_path = max(longest_path, dfs(r, c, matrix, mem));
            }
        }

        return longest_path;
    }
};