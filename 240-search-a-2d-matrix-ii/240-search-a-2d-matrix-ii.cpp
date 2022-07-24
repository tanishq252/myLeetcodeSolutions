class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i=rows-1;
        int j=0;
        while(i>=0 and j<cols){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                i--;
            }else if(matrix[i][j] < target){
                j++;
            }
        }
        return false;
    }
};