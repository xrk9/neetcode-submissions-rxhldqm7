class Solution {
private:
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
        TrieNode() : isWord(false) {
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for(const string& word : wordDict) {
            TrieNode* it = root;
            for(const char& c : word) {
                int id = c - 'a';
                if(!it->children[id]) {
                    it->children[id] = new TrieNode();
                }
                it = it->children[id];
            }
            it->isWord = true;
        }
        
        int ns = s.size();
        vector<int> visited(ns, 0);
        stack<int> st;
        st.push(0);

        while(!st.empty()) {
            int start = st.top(); 
            st.pop();
            
            if(start == ns) return true;
            if(visited[start]) continue;
            visited[start] = 1;

            TrieNode* curr = root;

            for(int end = start; end < ns; end++) {
                int id = s[end] - 'a';
                
                if(!curr->children[id]) {
                    break; 
                }
                
                curr = curr->children[id];
                
                if(curr->isWord) {
                    st.push(end + 1);
                }
            }
        }
        
        return false;
    }
};