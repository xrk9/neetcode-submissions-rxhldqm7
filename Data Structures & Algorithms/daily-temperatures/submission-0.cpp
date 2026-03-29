class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ts) {
        int n = ts.size();
        vector<int> out;
        out.resize(n);
        int arr[n];
        int top = -1;
        for(int i = 0; i<n;){
            if(top == -1 || ts[i]<=ts[arr[top]]){
                arr[++top] = i++;
            } else {
                out[arr[top--]] = i - arr[top];
            }
        }
        while(top!=-1){
            out[arr[top--]] = 0;
        }
        return out;
    }
};
