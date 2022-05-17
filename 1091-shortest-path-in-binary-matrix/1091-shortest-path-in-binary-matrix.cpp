class Solution {
public:

    bool valid(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        if(i>=0 and i<grid.size() and j>=0 and j<grid.size() and grid[i][j]==0 and visited[i][j]==false){
            return true;
        }
        return false;
    }
    
    void traverseNeighbours(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, queue<pair<int, int>>& nodes){
        for(int i = x-1;i<=x+1;i++){
            for(int j = y-1;j<=y+1;j++){
                if(valid(grid, i, j, visited)){
                    visited[i][j] = true;
                    nodes.push({i, j});
                }
            }
        }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n , vector<bool>(n, false));
        queue<pair<int, int>>  nodes;
        int totalNodes;
        int ans=0;
        
        if(grid[0][0] == 0){
            visited[0][0] = true;
            nodes.push({0,0});
        }
        
        
        while(!nodes.empty()){
                totalNodes = nodes.size();
                ans++;


            for(int k=0;k<totalNodes;k++){
                pair<int,int> initialNode = nodes.front();
                nodes.pop();
                int x = initialNode.first;
                int y = initialNode.second;
                if(x==n-1 and y==n-1) return ans;
                //here we traverse through all 8 neighbouring coordinates of a given point
                traverseNeighbours(grid, visited, x, y, nodes);
            }
        }
        
        return -1;
        
    }
};