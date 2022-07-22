class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, INT_MAX-10000));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 1){
                    if(i>0){
                        dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                    }
                    if(j>0){
                        dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(mat[i][j] == 1){
                    if(i<rows-1){
                        dp[i][j] = min(dp[i+1][j]+1, dp[i][j]);
                    }
                    if(j<cols-1){
                        dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp;
    }
};