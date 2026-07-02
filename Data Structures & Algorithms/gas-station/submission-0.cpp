class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int need = 0;
        int extra = 0;
        int pos = -1;
        for(int i = 0; i<n; i++){
            int diff = gas[i] - cost[i];
            extra+=diff;
            if(extra < 0){
                need -= extra;
                extra = 0;
                pos = -1;
            }else if(pos == -1) pos = i;
        }
        if(extra >= need) return pos;
        return -1;
    }
};
