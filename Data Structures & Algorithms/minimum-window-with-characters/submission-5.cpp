class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size(), tn = t.size();
        if(tn>sn) return "";
        unordered_map<char,int> f;
        f.reserve(tn);
        for(int i = 0; i<tn; i++){
            --f[t[i]];
        }
        int l = 0, r = -1;
        int i = 0, size = 9999;
        int len = 0;
        while((++r)<sn){
            if(f.contains(s[r])){
                if((f[s[r]]++)<0){
                    ++len;
                }
                if(len == tn){
                    while(true){
                        if(f.contains(s[l]) && f[s[l]]>=0){
                            --f[s[l]];
                            if(f[s[l]] < 0) break;
                        }
                        ++l;
                    }
                    int s = r - l + 1;
                    if(s<size){
                        size = s;
                        i = l;
                    }
                    ++l;--len;
                }
            }
        }
        if(size==9999) return "";
        return s.substr(i,size);
    }
};
