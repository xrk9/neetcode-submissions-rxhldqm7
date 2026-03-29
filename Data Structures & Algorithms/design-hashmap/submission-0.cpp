class Node{
    public:
        int key;
        int value;
        Node* next;

        Node(int k, int val){
            key = k;
            value = val;
            next = nullptr;
        }
};

class MyHashMap {
public:

    Node* arr[1000];

    MyHashMap() {
        for(int i = 0; i<1000; i++){
            arr[i] = nullptr;
        }
    }
    
    void put(int key, int value) {
        int index = key%1000;
        Node* node = arr[index];
        Node* newNode = new Node(key,value);
        if(get(key) == -1){
            newNode->next = arr[index];
            arr[index] = newNode;
        }else{
            while(node){
                if(node->key == key) node->value = value;
                node=node->next;
            }
        }
    }
    
    int get(int key) {
        int index = key%1000;
        Node* node = arr[index];
        while(node){
            if(node->key == key) return node->value;
            node=node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(get(key) == -1) return;
        int index = key%1000;
        Node* node = arr[index];
        if(node->key == key){
            arr[index] = node->next;
            delete node;
            return;
        }
        while(node->next){
            if(node->next->key == key){
                Node* tmp = node->next;
                node->next = tmp->next;
                delete tmp;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */