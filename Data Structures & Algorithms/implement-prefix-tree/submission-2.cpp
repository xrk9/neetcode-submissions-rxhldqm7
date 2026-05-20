class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode(){
        for(int i=0;i<26;++i) children[i] = nullptr;
        isWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* it = root;
        for(const char& c : word){
            int i = c - 'a';
            if(!it->children[i]){
                it->children[i] = new TrieNode();
            }
            it = it-> children[i];
        }
        it->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* it = root;
        for(const char& c : word){
            int i = c - 'a';
            if(!it->children[i]) return false;
            it = it->children[i];
        }
        return it->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* it = root;
        for(const char& c : prefix){
            int i = c - 'a';
            if(!it->children[i]) return false;
            it = it->children[i];
        }
        return true;
    }
};
