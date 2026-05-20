class PrefixTree {
private:
    struct TriNode{
        unordered_map<char, TriNode*> children;
        bool isWord=false;
    };
    TriNode* root;
public:
    PrefixTree() {
        root = new TriNode();
    }
    
    void insert(string word) {
        TriNode* it = root;
        for(const char& c: word){
            if(it->children.find(c) == it->children.end()){
                it->children[c] = new TriNode();
            }
            it = it->children[c];
        }
        it->isWord = true;
    }
    
    bool search(string word) {
        TriNode* it = root;
        for(const char& c: word){
            if(it->children.find(c) == it->children.end()) return false;
            it = it->children[c];
        }
        return it->isWord;
    }
    
    bool startsWith(string prefix) {
        TriNode* it=root;
        for(const char& c : prefix){
            if(it->children.find(c) == it->children.end()) return false;
            it = it->children[c];
        }
        return true;
    }
};
