auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n&1 == 1) return false;
        int q = -1;
        char arr[(n/2) + 1];
        for(int i = 0; i<n; i++){
            char c = s[i];
            if(c == '(' || c == '[' || c == '{'){
                arr[++q] = c;
            } else if (q>=0 && (c-arr[q] == 2 || c-arr[q] == 1)){
                --q;
            }else{
                return false;
            }
        }
        if(q==-1) return true;
        return false;
    }
};