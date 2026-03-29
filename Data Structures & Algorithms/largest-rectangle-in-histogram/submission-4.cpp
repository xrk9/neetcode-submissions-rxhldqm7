auto fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxA = 0;
        int id[1000];
        int h[1000];
        int top = -1;
        for(int i = 0; i < n; i++){
            int height = heights[i];
            int start = i; 
            while(top>=0 && h[top] > height) {
                maxA = max(maxA, h[top] * (i - id[top]));
                start = id[top--];
            }
            h[++top] = height;
            id[top] = start;
        }
        while(top >= 0){
            maxA = max(maxA, h[top] * (n - id[top--]));
        }
        return maxA;
    }
};