class Solution {
public:
    bool check(vector<vector<int>>& mat, int x, int y){
        for(int i=0;i<mat.size();i++){
            if(i==x){
               continue; 
            }
            if(mat[i][y] == 1){
                return false;
            }
        }
        for(int i=0;i<mat[0].size();i++){
            if(i==y){
               continue; 
            }
            if(mat[x][i] == 1){
                return false;
            }
        }
        return true;
    }
    
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    c+= (check(mat, i, j)) ? 1:0;
                }
            }
        }
        return c;
    }
};