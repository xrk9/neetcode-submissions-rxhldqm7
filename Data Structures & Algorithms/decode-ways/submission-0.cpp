class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0') return 0;
        if(n==1) return 1;
        
        int prev_2 = 1;
        int prev_1 = 1;
        for(int i = 1; i<n; i++){
            int curr = 0;
            if(s[i] != '0') curr += prev_1;

            bool a = s[i-1] == '1';
            bool b = s[i-1] == '2' && s[i] <= '6';

            if(a||b) curr += prev_2;

            if(curr == 0) return 0;

            prev_2 = prev_1;
            prev_1 = curr;

        }
        return prev_1;
        
    }
};
