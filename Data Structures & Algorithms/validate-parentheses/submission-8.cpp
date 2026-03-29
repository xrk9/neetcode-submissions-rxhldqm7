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
            } else if (q>=0 && abs(c-arr[q]) <= 2){
                --q;
            }else{
                return false;
            }
        }
        if(q==-1) return true;
        return false;
    }
};
