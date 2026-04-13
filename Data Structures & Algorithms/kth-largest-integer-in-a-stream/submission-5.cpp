class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minQ;
    int cap;
public:
    KthLargest(int k, vector<int>& nums) : cap(k) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            minQ.push(nums[i]);
            if(minQ.size() > cap){
                minQ.pop();
            }
        }
    }
    
    int add(int val) {
        minQ.push(val);
        if(minQ.size() > cap) minQ.pop();
        return minQ.top();
    }
};
