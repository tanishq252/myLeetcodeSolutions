class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int c= 1;
        for(int l=0;l<(n+1)/2;l++){
            for(int i = l;i<n-l;i++){
                ans[l][i] = c++;
            }
            for(int i = l+1;i<n-l;i++){
                ans[i][n-l-1] = c++;
            }
            for(int i = n-l-2;i>=l;i--){
                ans[n-1-l][i] = c++;
            }
            for(int i = n-l-2;i>=l+1;i--){
                ans[i][l] = c++;
            }
        }
        return ans;
    }
};