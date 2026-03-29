#include <array>
class TimeMap {
    unordered_map<string, array<string,1001>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string x = store[key][timestamp];
        if(!x.empty()){
            return x;
        }
        while(timestamp > 0){
            x = store[key][--timestamp];
            if(!x.empty()){
                return x;
            }
        }
        return "";
    }
};
