class MinStack {
    stack<pair<int,int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) s.emplace(val, val);
        else{
            s.emplace(val, min(s.top().second, val));
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
