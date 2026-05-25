class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        unordered_map<string, int> visited;
        queue<string> q;
        int nbfs=1;
        q.emplace(beginWord);
        while(!q.empty()){
            nbfs++;
            int len = q.size();
            for(int l = 0; l<len; l++){
                string word = q.front(); q.pop();
                visited[word]++;
                for(const string& s:wordList){
                    if(!visited[s]){
                        int m = s.size(), k=2;
                        for(int i = 0; i<m && k; i++){
                            if(word[i] != s[i]) k--;
                        }
                        if(!k) continue;
                        if(s==endWord) return nbfs;
                        q.emplace(s);
                    }
                }
            }
        }
        return 0;
    }
};
