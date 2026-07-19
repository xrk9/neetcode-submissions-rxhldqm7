class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < queries.size(); ++i) {
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        vector<int> res(queries.size(), -1);
        int pointer = 0;
        int n = intervals.size();
        
        for (auto& q : sorted_queries) {
            int query_val = q.first;
            int original_idx = q.second;
            
            while (pointer < n && intervals[pointer][0] <= query_val) {
                int size = intervals[pointer][1] - intervals[pointer][0] + 1;
                int end = intervals[pointer][1];
                minHeap.emplace(size, end);
                pointer++;
            }
            
            while (!minHeap.empty() && minHeap.top().second < query_val) {
                minHeap.pop();
            }
            
            if (!minHeap.empty()) {
                res[original_idx] = minHeap.top().first;
            }
        }
        
        return res;
    }
};