class Solution {
    unordered_map<char, vector<char>> adj;
    int visit[26]{0};
    bool isThere[26]{false};
    string res;
    bool dfs(char c){
        if(visit[c-'a'] == 1) return true;
        else if(visit[c-'a'] == -1) return false;

        visit[c-'a'] = -1;  // visiting
        for(const auto& nc : adj[c]){
            if(!dfs(nc)) return false;
        }
        visit[c-'a'] = 1;  //visited
        res+=c;
        isThere[c-'a'] = false;
        return true;
    }
public:
    string foreignDictionary(vector<string>& words) {
        for(const string& s : words)
            for(const char& c : s)
                isThere[c-'a'] = true;

        int n = words.size();
        for(int i = 1; i<n; i++){
            int idx = -1; char a, b;
            do{
                ++idx;
                a = words[i-1][idx];
                b = words[i][idx];
            }while(a != '\0' && a==b);
            if(a != '\0' && b == '\0') return "";
            if(a=='\0') continue;
            adj[b].emplace_back(a);
        }
        for(const auto& [c, v] : adj){
            if(!dfs(c)) return "";
        }
        for(char ch = 'a'; ch<='z'; ch++){
            if(isThere[ch-'a']) res+=ch;
        }
        return res;
    }
};
