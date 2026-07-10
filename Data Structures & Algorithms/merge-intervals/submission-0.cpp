class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for(const auto& interval : intervals){
            if(end >= interval[0]){
                end = max(end, interval[1]);
                continue;
            }
            res.push_back({start, end});
            start = interval[0];
            end = interval[1];
        }
        res.push_back({start, end});
        return res;
    }
};
