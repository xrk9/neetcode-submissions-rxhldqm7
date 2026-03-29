class StockSpanner {
private:
    pair<int,int> arr[100000];
    int top;
public:
    StockSpanner() {
        top = -1;
    }
    
    int next(int price) {
        if(top == -1){
            arr[++top] = {price,1};
            return 1;
        }
        int count = 1;
        while(top>=0 && arr[top].first <= price){
            count += arr[top].second;
            --top;
        }
        arr[++top] = {price,count};
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */