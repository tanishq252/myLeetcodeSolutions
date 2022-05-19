class Solution {
public:
    int mx = INT_MIN;
    
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
//     void dfs(int i,int j, vector<vector<int>>& matrix, vector<vector<int>> &dp, int x,int y){
//         // dp[x][y]++;
//         cout<<dp[x][y];
//         for(auto dir:dirs){
//             int m = i+dir[0];
//             int n = j+dir[1];
//             // cout<<m<<" "<<n;
//             if(m>=0 and n>=0 and m<matrix.size() and n<matrix[0].size()){
//                     dp[x][y]++;
//                     mx = max(mx, dp[x][y]);
//                     // dfs(m, n, matrix, dp, x, y);
//                 cout<<"ok";
//                 }
//         }
//     }
    
//     bool isValid(int i, int j, int k, int l, vector<vector<int>>& matrix){
//         if(k>=0 and l>=0 and k<matrix.size() and l<matrix[0].size()){
//              return true;}
//         return false;
//     }
    
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        
        for(auto dir:dirs){
            int x = i+dir[0];
            int y = j+dir[1];
            
            if(x>=0 and y>=0 and x<matrix.size() and y<matrix[0].size()){
                if(matrix[x][y]>matrix[i][j]){
                    ans = max(ans, dfs(x, y, matrix, dp));
                }
            }
        }
        
        dp[i][j] = ans+1;
        return dp[i][j];
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp (m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mx = max(mx,dfs(i, j, matrix, dp));
            }
        }
        return mx;
        
    }
};