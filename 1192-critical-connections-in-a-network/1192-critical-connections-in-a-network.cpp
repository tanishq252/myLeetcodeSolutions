class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> ans;
    vector<int> minTime;
    vector<int> firstTime;
    vector<bool> visited;
    int time = 1;
    
    void dfs(int node, int parent){
        firstTime[node] = minTime[node] = time++;
        visited[node] = true;
        
        for(auto child:graph[node]){
            if(child == parent) continue;
            if(!visited[child]) dfs(child, node);
            minTime[node] = min(minTime[node], minTime[child]);
            if(firstTime[node]<minTime[child]){
                ans.push_back({node, child});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n), minTime.resize(n), firstTime.resize(n), graph.resize(n);
        for(auto i:connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        dfs(0, -1);
        return ans;
    }
};