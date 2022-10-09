class Solution {
public:
    int ans=0,m,n;
    
    int recur(vector<vector<int>>& grid, int k, int i, int j, int sum, vector<vector<vector<int>>> &dp){
        if(i==m or j==n) return 0;
        if(i == m-1 and j == n-1){
            return (sum+grid[i][j])%k==0;
        }
        if(dp[i][j][sum] != -1){
            return dp[i][j][sum];
        }
        return dp[i][j][sum] = (recur(grid, k, i+1, j, (sum+grid[i][j])%k, dp)+recur(grid, k, i, j+1, (sum+grid[i][j])%k, dp))%1000000007;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (k+1, -1)));
        return recur(grid, k, 0, 0, 0, dp);
    }
};