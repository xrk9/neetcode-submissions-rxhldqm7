/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> mem;
        for(const auto& interval : intervals){
            mem.emplace_back(interval.start, 1);
            mem.emplace_back(interval.end, -1);
        }
        sort(mem.begin(), mem.end());
        int m = 0;
        int M = 0;
        for(const auto& items : mem){
            m+=items.second;
            if(m > M) M = m;
        }
        return M;
    }
};
