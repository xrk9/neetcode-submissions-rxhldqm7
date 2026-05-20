class Solution {
private:
    class TrieNode{
        public:
            TrieNode* children[26];

            TrieNode(){
                for(int i = 0; i<26; i++){
                    children[i] = nullptr;
                }
            }
    };
    int nrow;
    int ncol;
    TrieNode* root;

    void recurse(vector<vector<char>>& board, int r, int c, TrieNode* node, int count){
        if(count > 10 || r<0 || r>= nrow || c<0 || c>=ncol || board[r][c] == '#') return;
        char ch = board[r][c];
        int idx = ch - 'a';
        if(!node->children[idx]) node->children[idx] = new TrieNode();
        board[r][c] = '#';
        TrieNode* nxt = node->children[idx];

        recurse(board, r+1, c, nxt, count + 1);
        recurse(board, r-1, c, nxt, count + 1);
        recurse(board, r, c+1, nxt, count + 1);
        recurse(board, r, c-1, nxt, count + 1);
        board[r][c] = ch;
    }

    bool search(string prefix) {
        TrieNode* it = root;
        for(const char& c : prefix){
            int idx = c - 'a';
            if(!it->children[idx]) return false;
            it = it->children[idx];
        }
        return true;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        nrow = board.size();
        ncol = board[0].size();
        for(int r = 0; r<nrow; r++){
            for(int c = 0; c<ncol; c++){
                recurse(board, r, c, root,1);
            }
        }
        int writeidx = 0;
        int size = words.size();
        for(int i = 0; i < size; i++){
            if(search(words[i])) words[writeidx++] = words[i];
        }
        words.resize(writeidx);
        return words;
    }
};
