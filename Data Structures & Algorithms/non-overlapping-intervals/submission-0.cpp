class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int end = intervals[0][0];
        for(const auto& interval : intervals){
            if(end > interval[0]){
                end = min(end, interval[1]);
                ++res;
            }
            else end = interval[1];
        }
        return res;
    }
};
