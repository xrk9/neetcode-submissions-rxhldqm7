class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0];

        vector<vector<int>> key(grid);
        vector<vector<int>> visited(n, vector<int>(n,0));

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        typedef pair<int, int> pii;

        auto cmp = [&grid](const pii& a, const pii& b) {
            return grid[a.first][a.second] > grid[b.first][b.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);

        q.emplace(0, 0);

        while (!q.empty()) {
            auto [x_, y_] = q.top();
            visited[x_][y_] = 1;
            q.pop();
            for (const auto& dir : dirs) {
                int x = x_ + dir[0], y = y_ + dir[1];
                if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y]) continue;
                key[x][y] = max(key[x_][y_], key[x][y]);
                if (x == n - 1 && y == n - 1) return key[x][y];
                q.emplace(x, y);
            }
        }
        return 0;
    }
};
