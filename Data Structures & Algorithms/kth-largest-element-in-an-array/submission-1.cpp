class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(const int& n:nums){
            q.push(n);
            if(q.size() > k) q.pop();
        }
        return q.top();
    }
};
