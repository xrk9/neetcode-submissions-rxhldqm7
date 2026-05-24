class Solution {
    vector<int> parant;
    vector<int> rank;
    void makeSet(int i){
        parant[i] = i;
        rank[i] = 0;
    }
    int findSet(int i){
        while(parant[i] != i) i = parant[i];
        return i;
    }
    void unionSet(int a, int b){
        if(rank[a] < rank[b]){
            parant[a] = b;
        } else {
            parant[b] = a;
        }
        if(rank[a] == rank[b]) rank[a]++;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        parant.assign(V+1, -1);
        rank.resize(V+1);
        for(int i = 1; i<=V; i++) makeSet(i);
        for(const auto& edge:edges){
            int a = findSet(edge[0]), b = findSet(edge[1]);
            if(a == b) return edge;
            unionSet(a,b);
        }
        return {};
    }
};
