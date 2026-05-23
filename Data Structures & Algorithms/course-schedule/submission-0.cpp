class Solution {
private:
    vector<unordered_set<int>> adjacentList;
    int n;
    vector<int> visited;
    void check(int i){
        visited[i] = -1;
        if(adjacentList[i].empty()){
            visited[i] = 1;
            return;
        }
        int flag = 0;
        for(const int& n : adjacentList[i]){
            if(!visited[n]) check(n);
            if(visited[n] == -1) {
                visited[i] = -1;
                return;
            }
        }
        visited[i] = 1;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        adjacentList.resize(n);
        visited.resize(n);
        for(const auto& p:prerequisites){
            adjacentList[p[0]].insert(p[1]);
        }
        for(int i = 0; i<n; i++){
            if(!visited[i]) check(i);
            if(visited[i] == -1) return false;
        }
        return true;
    }
};
