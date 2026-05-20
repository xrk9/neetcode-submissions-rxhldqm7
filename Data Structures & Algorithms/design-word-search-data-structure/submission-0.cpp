class WordDictionary {
private:
    class TrieNode{
        public:
            TrieNode* children[26];
            string exists;
            bool isWord;
            
            TrieNode(){
                for(int i = 0; i<26; i++){
                    children[i] = nullptr;
                }
                exists = "";
                isWord = false;
            }
    };
    bool helper(int id, const string& word, TrieNode* root) {
        if(word[id] == '\0'){
            return root->isWord;
        }
        TrieNode* it = root;
        char c = word[id];
        if(c == '.'){
            if(it->exists.empty()) return false;
            for(const char& ch:it->exists){
                int idx = ch - 'a';
                if(helper(id+1, word, it->children[idx])) return true;
            }
            return false;
        }
        else{
            int idx = c - 'a';
            if(!it->children[idx]) return false;
            return helper(id+1, word, it->children[idx]);
        }
    }
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* it = root;
        for(const char& c: word){
            int idx = c - 'a'; // index in children array
            if(!it->children[idx]){
                it->children[idx] = new TrieNode();
                it->exists+=c;    
            }
            it = it->children[idx];
        }
        it->isWord = true;
    }
    
    bool search(string word) {
        return helper(0, word, root);
    }
};
