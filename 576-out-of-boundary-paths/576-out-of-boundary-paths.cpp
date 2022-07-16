class Solution {
public:
    int mod = 1000000007;
    int findPaths(int m, int n, int N, int startRow, int startColumn) {
        vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>(N+1, -1)));
        return findP(m, n, N, startRow, startColumn, v);

    }
    
    int findP(int m, int n, int N, int i, int j, vector<vector<vector<int>>> &v){
        // if we are beyond the last index or before the first index we say that this is one way, further incrementing the count
        if(i==m or j == n or i<0 or j<0 ) return 1;
        
        //if we are out of moves return 0
        if (N==0) return 0;
        
        //if we have alraedy visited the element then vaLue will not be -1 which is initial value
        if(v[i][j][N]>=0) return v[i][j][N];
        
        v[i][j][N] = ((findP(m, n, N-1, i-1, j, v)%mod +
            findP(m, n, N-1, i+1, j, v)%mod)%mod +
            (findP(m, n, N-1, i, j+1, v)%mod +
            findP(m, n, N-1, i, j-1, v)%mod)%mod )%mod;
    
        return v[i][j][N];
        
    }
};