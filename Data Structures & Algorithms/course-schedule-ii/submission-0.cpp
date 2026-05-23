class Solution {
private:    
    vector<int> res;
    vector<int> visited;
    vector<vector<int>> adjList;
    int n = 0;
    void check(int i){
        visited[i] = -1;
        for(const int& n:adjList[i]){
            if(!visited[n]) check(n);
            if(visited[n] == -1){
                visited[i] == -1;
                return;
            }
        }
        visited[i] = 1;
        res[n++] = i;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        visited.resize(numCourses);
        adjList.resize(numCourses);
        res.resize(numCourses);
        for(const auto& it : p){
            adjList[it[0]].push_back(it[1]);
        }
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]) check(i);
            if(visited[i] == -1) return {};
        }
        return res;
    }
};
