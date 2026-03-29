class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxA = 0;
        vector<pair<int,int>> stak;
        stak.reserve(n);
        for(int i = 0; i < n; i++){
            int h = heights[i];
            int start = i; 
            while(!stak.empty() && stak.back().second > h) {
                pair<int, int> top = stak.back();
                stak.pop_back();
                maxA = max(maxA, top.second * (i - top.first));
                start = top.first;
            }
            stak.emplace_back(start, h);
        }
        while(!stak.empty()){
            maxA = max(maxA, stak.back().second * (n - stak.back().first));
            stak.pop_back();
        }
        return maxA;
    }
};