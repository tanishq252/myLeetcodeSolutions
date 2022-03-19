class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v;
        for(int j=0;j<m;j++){
                    int min = INT_MAX;
        int min_col=0;

            for(int i=0;i<n;i++){
                if(matrix[j][i]<min){
                    min = matrix[j][i];
                    min_col = i;
                }
            }
            int flag=0;
            for(int k=0;k<m;k++){
                if(matrix[k][min_col]>min){
                    flag=1;
                    break;
                }
            }
            if(flag == 0){v.push_back(min);}
        }
        return v;
    }
};