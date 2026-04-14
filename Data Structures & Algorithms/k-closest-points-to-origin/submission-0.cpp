class Solution {
private:
    struct compare{
        bool operator()(vector<int> a, vector<int> b){
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> q;
        int n = points.size();
        for(int i = 0; i<n; i++){
            q.push(points[i]);
            if(q.size() > k) q.pop();
        }
        vector<vector<int>> res;
        for(int i = 0; i<k; i++){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
