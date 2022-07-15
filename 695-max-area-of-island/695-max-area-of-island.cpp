class Solution {
public:
    
    int recur(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int sum = 1;
        visited[i][j] = true;
        if(i != grid.size()-1){
            if(grid[i+1][j]==1 and !visited[i+1][j]){
                sum += recur(i+1, j, grid, visited);
            }
        }
        if(i!=0){
            if(grid[i-1][j]==1 and !visited[i-1][j]){
                sum += recur(i-1, j, grid, visited);
            }
        }
        if(j != grid[0].size()-1){
            if(grid[i][j+1]==1 and !visited[i][j+1]){
                sum += recur(i, j+1, grid, visited);
            }
        }
        if(j!=0){
            if(grid[i][j-1]==1 and !visited[i][j-1]){
                sum += recur(i, j-1, grid, visited);
            }
        }
        
        return sum;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        priority_queue<int> pq;
        pq.push(0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    pq.push(recur(i, j, grid, visited));
                }
            }
        }
        cout<<pq.top();
        return pq.top();
        
    }
};