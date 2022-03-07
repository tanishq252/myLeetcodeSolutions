class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n!=r*c){return mat;}
        vector<vector<int>> myMat;
        vector<int> allElements;
        
        for(auto row:mat){
            for(auto ele:row){
                allElements.push_back(ele);
            }
        }
        int pos = 0;
        for(int i=0;i<r;i++){
            vector<int> row;
            for(int j=0;j<c;j++){
                row.push_back(allElements[pos]);
                pos++;
            }
            myMat.push_back(row);
        }
        return myMat;
    }
};