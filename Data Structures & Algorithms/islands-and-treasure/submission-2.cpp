class Solution {
private:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    queue<pair<int,int>> q;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                if(grid[r][c] == 0) q.push({r,c});
            }
        }
        int dist = 0;
        while(q.size()){
            dist++;
            int len = q.size();
            for(int l=0;l<len;l++){
                auto [x,y] = q.front();q.pop();
                for(auto const& d:dirs){
                    int i=x+d[0], j=y+d[1];
                    if(i<0||j<0||i>=nrow||j>=ncol||
                        grid[i][j]<0 || 
                        grid[i][j]<dist
                        )continue;
                    grid[i][j] = dist;
                    q.push({i,j});
                }
            }
        }
    }
};
