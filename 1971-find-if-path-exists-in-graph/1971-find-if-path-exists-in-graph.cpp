class Solution {
public:
    bool bfs(vector<vector<int>> &adjList, int start, int dest){
        vector<int> visited(adjList.size(), 0);
        visited[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int start = q.front();
            q.pop();
            for(auto i:adjList[start]){
                if(visited[i]==0){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        return visited[dest];
    }
    
    // bool dfs(vector<vector<int>> &adjList, int start, int dest){
    //     re
    // }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);            
            adj[i[1]].push_back(i[0]);
        }
        
        return bfs(adj, source, destination);;
    }
};