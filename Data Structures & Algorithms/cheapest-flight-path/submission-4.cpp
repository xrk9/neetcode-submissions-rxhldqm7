class Solution {
    struct Flight{
        int des, dis, used;
        Flight(int des_, int dis_) : des(des_), dis(dis_), used(0) {}
    };
    unordered_map<int, vector<Flight>> adj;
    int res = INT_MAX, des;

    void dfs(int curr, int currDis, int k){
        if(curr == des){
            res = min(res, currDis);
            return;
        }else if(currDis > res || k-- <= 0) return;
        for(auto& flight : adj[curr]){
            if(!flight.used){
                flight.used = 1;
                dfs(flight.des, currDis + flight.dis, k);
                flight.used = 0;
            }
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        des = dst;
        for(const auto& flight : flights){
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }
        for(auto& flight : adj[src]){
            flight.used = 1;
            dfs(flight.des, flight.dis, k);
        }
        return res == INT_MAX ? -1 : res;
    }
};
