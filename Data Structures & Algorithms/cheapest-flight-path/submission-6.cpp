class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& flight : flights)
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        vector<int> stops(n, INT_MAX); 
        
        using Type = tuple<int, int, int>;
        priority_queue<Type, vector<Type>, greater<Type>> q;
        
        q.emplace(0, src, 0);
        
        while(!q.empty()) {
            auto [currDist, currDest, currStops] = q.top(); 
            q.pop();
            
            if(currDest == dst) return currDist;
            
            if(currStops > k) continue;
            
            if(currStops >= stops[currDest]) continue;
            stops[currDest] = currStops;
            
            for(const auto& [nxtDest, flightDist] : adj[currDest]){
                q.emplace(currDist + flightDist, nxtDest, currStops + 1);
            }
        }
        
        return -1;
    }
};