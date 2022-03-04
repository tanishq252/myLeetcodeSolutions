class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> v(m, vector<int>(n,0));
        int c = 0;
        for(int i=0;i<indices.size();i++){
            for(int j = 0;j<n;j++){
                v[indices[i][0]][j]++;
            }
            for(int j = 0;j<m;j++){
                v[j][indices[i][1]]++;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]%2!=0){c++;}
            }
        }
        return c;
    }
};