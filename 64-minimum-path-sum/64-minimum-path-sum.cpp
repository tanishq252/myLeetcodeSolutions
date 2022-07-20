class Solution {
public:
    int minVisitedAdjacentNeighbour(vector<vector<int>> &grid,vector<vector<bool>> &visited, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        int mnm = INT_MAX;
        if(i!=0){
            if(visited[i-1][j]){
                mnm = min(mnm, grid[i-1][j]);
            }
        }
        if(j!=0){
            if(visited[i][j-1]){
                mnm = min(mnm, grid[i][j-1]);
            }
        }
        if(i!=m-1){ 
            if(visited[i+1][j]){
                mnm = min(mnm, grid[i+1][j]);
            }
        }
        if(j!=n-1){
            if(visited[i][j+1]){
                mnm = min(mnm, grid[i][j+1]);
            }
        }
        return (mnm == INT_MAX)?0:mnm;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = true;
                grid[i][j]+=minVisitedAdjacentNeighbour(grid, visited, i, j);
            }
        }
        return grid[m-1][n-1];
    }
};