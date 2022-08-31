class Solution {
public:
     void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;
        //up
        if (i-1 >= 0 && visited[i-1][j] != true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix, visited, i-1, j);
        //down
        if (i+1 < m && visited[i+1][j] != true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix, visited, i+1, j);
        //left
        if (j-1 >= 0 && visited[i][j-1] != true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix, visited, i, j-1);
        //right
        if (j+1 <n && visited[i][j+1] != true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix, visited, i, j+1);

    }
    
//     void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
//         int m = heights.size(), n = heights[0].size();
        
//         visited[i][j] = true;
        
//         if(i>0 and visited[i-1][j]!=true and (heights[i-1][j] >= heights[i][j])){
//             dfs(heights, visited, i-1, j);
//         }
//         if(i<m-1 and visited[i+1][j]!=true and (heights[i+1][j] >= heights[i][j])){
//             dfs(heights, visited, i+1, j);
//         }
//         if(j>0 and visited[i][j-1]!=true and (heights[i][j-1] >= heights[i][j])){
//             dfs(heights, visited, i, j-1);
//         }
//         if(j<n-1 and visited[i-1][j]!=true and (heights[i][j+1] >= heights[i][j])){
//             dfs(heights, visited, i, j+1);
//         }
//     }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        if(m==0 or n==0) return ans;
        vector<vector<bool>> atl(m, vector<bool> (n));                               vector<vector<bool>> pac(m, vector<bool> (n));
        
        for(int i=0;i<m;i++){
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, n-1);
        }
        
        for(int i=0;i<n;i++){
            dfs(heights, pac, 0, i);
            dfs(heights, atl, m-1, i);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atl[i][j] and pac[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
