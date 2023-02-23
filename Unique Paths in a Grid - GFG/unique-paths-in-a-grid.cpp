//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n, vector<int> (m,1)), ddp(n, vector<int> (m,1));
        n-=1, m-=1;
        
        dp=grid;
        
        int mod = 1000000007;
        
        if(grid[n][m]==0) return 0;
        // if(n==0){
            for(int i=1;i<=m;i++){
                if(grid[0][i]==0) dp[0][i]=0;
                else dp[0][i]=dp[0][i-1];
            }
            // return 1;
        // }
        // if(m==0){
            for(int i=1;i<=n;i++){
                if(grid[i][0]==0) dp[i][0]=0;
                else dp[i][0]=dp[i-1][0];
            }
        //     return 1;
        // }
         
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         if(grid[i][j]==0){
        //             dp[i][j]=0;
        //         }
        //     }
        // }
        
        // dp = grid;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j]!=0){
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                }
            }
        }
        return dp[n][m]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends