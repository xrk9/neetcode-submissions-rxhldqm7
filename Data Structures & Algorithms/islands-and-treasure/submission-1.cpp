class Solution {
private:
    int nrow, ncol;
    void dfs(vector<vector<int>>& grid, int r, int c, int d){
        if(r<0 || c<0 || r>=nrow || c>=ncol || grid[r][c] < d) return;
        grid[r][c] = d++;
        dfs(grid, r+1, c, d);
        dfs(grid, r-1, c, d);
        dfs(grid, r, c-1, d);
        dfs(grid, r, c+1, d);
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        nrow = grid.size();
        ncol = grid[0].size();
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                if(grid[r][c] == 0) dfs(grid, r, c, 0);
            }
        }
    }
};
