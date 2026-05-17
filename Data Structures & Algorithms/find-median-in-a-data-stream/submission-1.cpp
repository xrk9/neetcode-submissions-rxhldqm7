class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.emplace(num);
        right.emplace(left.top()); left.pop();

        if(left.size() < right.size()){
            left.emplace(right.top()); right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        return (left.top()+right.top())/2.0f;
    }
};
