class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i<k-1; i++){
            pq.emplace(nums[i], i);
        }
        vector<int> res;
        int l = 0, r = k - 1;
        while(r<n){
            pq.emplace(nums[r], r);
            auto top = pq.top();
            if(top.second < l){
                pq.pop();
                continue;
            }
            res.emplace_back(top.first);
            r++; l++;
        }
        return res;
    }
};
