class Solution {
    int nrow, ncol;
    int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<char>>& ocean, int r, int c) {
        ocean[r][c] = 1;
        
        for(const auto& d : dirs) {
            int r_ = r + d[0];
            int c_ = c + d[1];
        
            if(r_ >= 0 && r_ < nrow && c_ >= 0 && c_ < ncol && 
               !ocean[r_][c_] && heights[r_][c_] >= heights[r][c]) {
                dfs(heights, ocean, r_, c_);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        nrow = heights.size();
        ncol = heights[0].size();
        
        vector<vector<char>> pacific(nrow, vector<char>(ncol, 0));
        vector<vector<char>> atlantic(nrow, vector<char>(ncol, 0));
        
        // left pacific and right atlantic
        for (int r = 0; r < nrow; r++) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, ncol - 1);
        }
        
        // top pacific and bottom atlantic
        for (int c = 0; c < ncol; c++) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, nrow - 1, c);
        }
        
        vector<vector<int>> res;
        for (int r = 0; r < nrow; r++) {
            for (int c = 0; c < ncol; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        
        return res;
    }
};