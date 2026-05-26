class Solution {
public:
    void dfs(string curr, unordered_map<string, vector<string>>& adj, vector<string>& res) {
        while (!adj[curr].empty()) {
            string next = adj[curr].back();
            adj[curr].pop_back();
            dfs(next, adj, res);
        }
        res.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        
        for (auto& [key, neighbours] : adj) {
            sort(neighbours.rbegin(), neighbours.rend());
        }
        
        vector<string> res;
        dfs("JFK", adj, res);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};