class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row =0;
        for(int i=0;i<matrix.size();i++){
            row = (target <= *max_element(matrix[i].begin(), matrix[i].end())) ? i : -1 ;
            if(row!=-1){break;}
        }
        cout<<row;
        if(row==-1){return false;}
        int i=0;
        int j=matrix[0].size()-1;
        while(i<=j){
            if(matrix[row][i] == target || matrix[row][j] == target){return true;}
            else if(matrix[row][i] < target){i++;}
            else if(matrix[row][j] > target){j--;}
        }
        return false;
    }
};