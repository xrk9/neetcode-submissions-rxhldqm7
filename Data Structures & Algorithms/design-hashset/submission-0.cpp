class Node{
    public: 
        int value;
        Node* next;

        Node(){
            value = 0;
            next = nullptr;
        }

        Node(int val){
            value = val;
            next = nullptr;
        }
};

class MyHashSet {
public:

    Node* arr[10000];

    MyHashSet() {
        for(int i = 0; i<10000; i++){
            arr[i] = nullptr;
        }
    }
    
    void add(int key) {
        if(contains(key)) return;
        Node* node = new Node(key);
        int index = key%10000;
        node->next = arr[index];
        arr[index] = node;
    }
    
    void remove(int key) {
        int index = key%10000;
        Node* node = arr[index];
        if(node == nullptr) return;
        if(node->value == key){
            arr[index] = node->next;
            delete node;
            return;
        }
        while(node->next && node->next->value != key) node = node->next;
        if(node->next == nullptr) return;
        Node* tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
    
    bool contains(int key) {
        int index = key%10000;
        Node* node = arr[index];
        if(node == nullptr) return false;
        while(node != nullptr){
            if(node->value == key) return true;
            node=node->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */