class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(const auto& edge:times){
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }
        vector<int> weight(n+1, INT_MAX);
        weight[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0,k);
        while(!pq.empty()){
            auto [w, v] = pq.top(); pq.pop();
            for(const auto& [v_, w_] : adj[v]){
                if(weight[v] + w_ < weight[v_]){
                    weight[v_] = weight[v] + w_;
                    pq.emplace(w_,v_);
                }
            }
        }
        int time=0;
        for(int i = 1; i<=n; i++) time = max(time, weight[i]);
        return (time == INT_MAX ? -1 : time);
    }
};
