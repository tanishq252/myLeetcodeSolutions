class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        //rows
        for(int i=0;i<m;i++){
            vector<int> v;
            int row=i, col=0;
            while(row<m and col<n){
                v.push_back(mat[row++][col++]);
            }
            sort(v.begin(), v.end());
            row = i, col = 0;
            int j=0;
            while(row<m and col<n){
                mat[row++][col++] = v[j++];
            }
        }
        //cols
        for(int i=1;i<n;i++){
            vector<int> v;
            int row=0, col=i;
            while(row<m and col<n){
                v.push_back(mat[row++][col++]);
            }
            sort(v.begin(), v.end());
            row = 0, col =i;
             int j=0;
            while(row<m and col<n){
                mat[row++][col++] = v[j++];
            }
        }
        return mat;
    }
};