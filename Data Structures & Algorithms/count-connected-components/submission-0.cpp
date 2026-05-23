class Solution {
    vector<vector<int>> adj;
    vector<int> visited;
    void dfs(int i){
        visited[i] = 1;
        for(const int& n : adj[i])
            if(!visited[n]) dfs(n);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n);
        for(const auto& p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        int ndfs = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                ndfs++;
                dfs(i);
            }
        }
        return ndfs;
    }
};
