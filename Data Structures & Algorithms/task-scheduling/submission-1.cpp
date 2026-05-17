class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counts[26] = {0};
        for(const char& task:tasks){
            ++counts[task-'A'];
        }
        vector<int> freq;
        for(const int& count:counts){
            if(count!=0) freq.emplace_back(count);
        }
        priority_queue<int> maxHeap(freq.begin(), freq.end());
        queue<pair<int,int>> Q;
        int clock = 0;
        while(!maxHeap.empty() || !Q.empty()){
            ++clock;
            if(!Q.empty()){
                auto [f, c] = Q.front();
                if(c==clock){
                    Q.pop();
                    maxHeap.emplace(f);
                }
            }
            if(!maxHeap.empty()){
                int f = maxHeap.top();
                maxHeap.pop();
                if(f>1){
                    Q.emplace(f-1, clock + n + 1);
                }
            }
        }
        return clock;
    }
};
