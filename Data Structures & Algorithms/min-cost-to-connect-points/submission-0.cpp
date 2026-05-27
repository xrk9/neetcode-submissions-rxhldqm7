class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        struct Edge {
            int a, b, w;
            Edge(int a_, int b_, int w_) : a(a_), b(b_), w(w_) {}
        };
        
        int V = points.size();
        
        vector<Edge> edges;
        
        // Lambda for weight calculation
        auto weight = [](const vector<int>& a, const vector<int>& b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                edges.emplace_back(i, j, weight(points[i], points[j]));
            }
        }

        vector<int> parant(V);
        vector<int> rank(V, 0);
        iota(parant.begin(), parant.end(), 0);

        // Lambda for findSet
        auto findSet = [&](int id) {
            // Find root
            int root = id;
            while (root != parant[root]) {
                root = parant[root];
            }
            while (id != root) {
                int next = parant[id];
                parant[id] = root;
                id = next;
            }
            return root;
        };
        
        // Lambda for Union
        auto setUnion = [&](int a, int b) {
            if (rank[a] < rank[b]) {
                parant[a] = b;
            } else {
                parant[b] = a;
                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        };

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w > b.w;
        });
        
        int totalWeight = 0;
        int nEdges = 0;
        
        while (nEdges < V - 1) {
            Edge e = edges.back(); 
            edges.pop_back();
            
            int rootA = findSet(e.a);
            int rootB = findSet(e.b);
            
            if (rootA != rootB) {
                totalWeight += e.w;
                setUnion(rootA, rootB);
                nEdges++;
            }
        }
        
        return totalWeight;
    }
};