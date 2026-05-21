class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                if(grid[r][c] == 2) q.push({r,c});
                else if (grid[r][c] == 1) ++fresh;
            }
        }

        int min = 0;
        while(q.size() && fresh){
            ++min;
            int len = q.size();
            for(int l = 0; l<len; l++){
                auto [r_,c_] = q.front(); q.pop();
                for(const auto& dir:dirs){
                    int r = r_ + dir[0];
                    int c = c_ + dir[1];

                    if(r<0 || c<0 || r>=nrow || c>=ncol || grid[r][c] != 1) continue;
                    --fresh;
                    grid[r][c] = 2;
                    q.push({r,c});
                }
            }
        }

        return fresh?-1:min;
    }
};
