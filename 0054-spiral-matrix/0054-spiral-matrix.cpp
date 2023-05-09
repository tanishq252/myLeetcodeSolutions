class Solution {
public:
    int final_size;
    void storeData(int sx, int ex, int sy, int ey, vector<int> &ans, vector<vector<int>> &mat){
        if(sx>ex or sy>ey) return;
        int i = sx, j=sy;
        while(j<=ey){
            ans.push_back(mat[i][j]);
            if(ans.size() == final_size) return;
            j++;
        }
        j--;i++;
        while(i<=ex){
            ans.push_back(mat[i][j]);
            if(ans.size() == final_size) return;
            i++;
        }
        i--;j--;
        while(j>=sy){
            ans.push_back(mat[i][j]);
            if(ans.size() == final_size) return;
            j--;
        }
        j++;i--;
        while(i>sx){
            ans.push_back(mat[i][j]);
            if(ans.size() == final_size) return;
            i--;
        }
        storeData(sx+1,ex-1, sy+1, ey-1, ans, mat);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        final_size = m*n;
        storeData(0, m-1, 0, n-1, ans, matrix);
        return ans;
    }
};