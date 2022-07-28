class Solution {
public:
    bool isCycle(int node, vector<vector<int>> &adjacencyList, vector<int> &visited){
        if(visited[node] == 1){
            return true;
        }
        if(visited[node]==0){
            //start of the search for cycle
            visited[node] = 1;
            for(auto child:adjacencyList[node]){
                if(isCycle(child, adjacencyList, visited)){
                    return true;
                }
            }
        }
        visited[node] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0 ){
            return true;
        }
        
        vector<vector<int>> adjacencyList(numCourses);        
        vector<int> visited(numCourses, 0);

        for(auto i:prerequisites){
            if(i[0] == i[1]) return false;
            adjacencyList[i[0]].push_back(i[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(isCycle(i, adjacencyList, visited)){
                return false;
            }
        }

        return true;
    }
};