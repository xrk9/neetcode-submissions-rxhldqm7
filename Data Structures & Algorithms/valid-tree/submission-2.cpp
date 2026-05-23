class Solution {
private:
    vector<vector<int>> adjList;
    vector<int> visited;
    void dfs(int i){
        visited[i] = 1;
        for(const int& n : adjList[i])
            if(!visited[n]) dfs(n);
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return true;
        else if(edges.size() != n-1) return false;
        adjList.resize(n);
        visited.resize(n);
        for(const auto& p : edges){
            adjList[p[0]].push_back(p[1]);
            adjList[p[1]].push_back(p[0]);
        }
        dfs(edges[0][1]);
        
        for(int i = 0; i<n; i++)
            if(!visited[i]) return false;
        
        return true;
    }
};
