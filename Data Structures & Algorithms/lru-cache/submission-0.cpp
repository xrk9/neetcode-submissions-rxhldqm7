class LRUCache {
private:
    struct Node{
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int key, int value) : next(nullptr), prev(nullptr), key(key), val(value) {}
    };
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void remove(Node* n){
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }
    void mkHead(Node* n){
        n->prev = head;
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
    }

public:
    LRUCache(int capacity): cap(capacity), head(new Node(-1,-1)), tail(new Node(-1,-1)) {
        head->next = tail;
        tail->prev = head;
        cache.reserve(capacity);
    }
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        Node* n = cache[key];
        remove(n); mkHead(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            if(cache.size() == cap){
                Node* n = tail->prev;
                cache.erase(n->key);
                remove(n);
                n->val = value;
                n->key = key;
                mkHead(n);
                cache[key] = n;
            }else{
                Node* n = new Node(key,value);
                cache[key] = n;
                mkHead(n);
            }
        }else{
            Node* n = cache[key];
            remove(n);
            mkHead(n);
            n->val = value;
        }
    }
};
