class Solution {
public:
    void setRowsCols(vector<vector<int>>& matrix, vector<bool> &rows, vector<bool> &cols, int i, int j){
        if(!rows[i]){
            for(int x=0;x<cols.size();x++){
                matrix[i][x] = 0;
            }
        }
        if(!cols[j]){
            for(int x=0;x<rows.size();x++){
                matrix[x][j] = 0;
            }
        }
        rows[i] = true;
        cols[j] = true;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rows(matrix.size(), false);        
        vector<bool> cols(matrix[0].size(), false);
        vector<vector<bool>> visited(rows.size(), vector<bool> (cols.size(), false));
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<cols.size();j++){
                if(matrix[i][j] == 0){
                    visited[i][j] = true;
                    rows[i] = true; cols[j] = true;
                }
            }
        }
        for(int i=0;i<rows.size();i++){
            if(rows[i]){
                for(int x=0;x<cols.size();x++){
                    matrix[i][x] = 0;
                }
            }
        }
        for(int i=0;i<cols.size();i++){
            if(cols[i]){
                for(int x=0;x<rows.size();x++){
                    matrix[x][i] = 0;
                }
            }
        }
        // for(int i=0;i<rows.size();i++){
        //     for(int j=0;j<cols.size();j++){
        //         if(matrix[i][j] == 0 and visited[i][j]){
        //             setRowsCols(matrix, rows, cols, i, j);
        //         }
        //     }
        // }
        
    }
};