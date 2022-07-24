class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=m-1;
        int j=0;
        
        while(i>=0 and j<n){
            if(matrix[i][j] < target){
                j++;
            }else if(matrix[i][j] > target){
                i--;
            }else{
                return true;
            }
        }
        
        return false;
    }
};