class Solution {
private:
    class TrieNode{
        public:
            TrieNode* children[26];
            string w;

            TrieNode(){
                for(int i = 0; i<26; i++){
                    children[i] = nullptr;
                }
                w = "";
            }
    };
    int nrow;
    int ncol;
    TrieNode* root;

    vector<string> res;

    void recurse(vector<vector<char>>& board, int r, int c, TrieNode* node, int len){
        if(len > 10 || r<0 || c<0 || r>=nrow || c>= ncol || board[r][c] == '#') return;
        char ch = board[r][c];
        int idx = ch - 'a';
        if(!node->children[idx]) return;
        TrieNode* nxt = node->children[idx];
        if(!nxt->w.empty()){
            res.emplace_back(nxt->w);
            nxt->w = "";
        }
        board[r][c] = '#';
        recurse(board, r+1, c, nxt, len+1);
        recurse(board, r-1, c, nxt, len+1);
        recurse(board, r, c+1, nxt, len+1);
        recurse(board, r, c-1, nxt, len+1);
        board[r][c] = ch;

    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        nrow = board.size();
        ncol = board[0].size();

        // Make Trie
        for(const string& word:words){
            TrieNode* it = root;
            for(const char& ch : word){
                int idx = ch - 'a';
                if(!it->children[idx]) it->children[idx] = new TrieNode();
                it = it->children[idx];
            }
            it->w = word;
        }

        // Scan the board for words
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                recurse(board, r, c, root, 1);
            }
        }

        return res;
    }
};
