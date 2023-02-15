//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
        int m = heights.size(), n = heights[0].size();
        
        visited[i][j] = true;
        
        if(i>0 and visited[i-1][j]!=true and (heights[i-1][j] >= heights[i][j])){
            dfs(heights, visited, i-1, j);
        }
        if(i<m-1 and visited[i+1][j]!=true and (heights[i+1][j] >= heights[i][j])){
            dfs(heights, visited, i+1, j);
        }
        if(j>0 and visited[i][j-1]!=true and (heights[i][j-1] >= heights[i][j])){
            dfs(heights, visited, i, j-1);
        }
        if(j<n-1 and visited[i][j+1]!=true and (heights[i][j+1] >= heights[i][j])){
            dfs(heights, visited, i, j+1);
        }
    }
    int water_flow(vector<vector<int>> &heights,int N,int M){
    // Write your code here.
        int ans=0;
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
                    ans++;
                }
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends