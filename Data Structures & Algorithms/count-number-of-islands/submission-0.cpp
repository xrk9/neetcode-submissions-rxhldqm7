class Solution {
private:
    int nrow, ncol, n = 0;
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || r>=nrow || c<0 || c>=ncol || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        nrow = grid.size();
        ncol = grid[0].size();
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                if(grid[r][c] == '1'){
                    dfs(grid, r, c); ++n;
                }
            }
        }
        return n;
    }
};
