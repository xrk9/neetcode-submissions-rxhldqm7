class Solution {
public:
    int numDistinct(string s, string t) {
        int nt = t.size();
        int ns = s.size();

        if(nt > ns) return 0;

        vector<vector<int>> mem(nt + 1, vector<int>(ns + 1, 0));
        for(int i = 0; i<=ns; i++){
            mem[0][i] = 1;
        }
        for(int r = 1; r<=nt; r++){
            int curr = 0;
            for(int c = 1; c<=ns; c++){
                if(t[r-1] == s[c-1]) curr += mem[r-1][c-1];
                mem[r][c] = curr;
            }
        }
        return mem[nt][ns];
    }
};
