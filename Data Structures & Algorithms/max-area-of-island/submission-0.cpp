class Solution {
private:
    int nrow,ncol;
    int maxArea = 0;
    int runningArea;
    void dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0 || r>=nrow || c<0 || c>=ncol || grid[r][c] == 0) return;
        grid[r][c] = 0;
        ++runningArea;
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        nrow = grid.size();
        ncol = grid[0].size();
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                if(grid[r][c]){
                    runningArea = 0;
                    dfs(grid, r, c);
                    maxArea = max(maxArea, runningArea);
                }
            }
        }
        return maxArea;
    }
};
