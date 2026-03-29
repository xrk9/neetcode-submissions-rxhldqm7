class FreqStack {
private:
    unordered_map<int,int> count;
    vector<int> stk[20000];
    int mx;
    
public:
    FreqStack() {
        for(int i = 0; i<20000; i++){
            stk[i].reserve(8);
        }
        mx = 0;
    }
    
    void push(int val) {
        stk[count[val]++].push_back(val);
        mx = max(mx,count[val]-1);
    }
    
    int pop() {
        int val = stk[mx].back();
        stk[mx].pop_back();
        --count[val];
        if(stk[mx].empty()){
            --mx;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */