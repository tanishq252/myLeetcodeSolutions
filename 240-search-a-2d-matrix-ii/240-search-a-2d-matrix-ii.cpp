class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(target < matrix[0][0] || target> matrix[m-1][n-1]){return false;}        
        if(target == matrix[0][0] || target== matrix[m-1][n-1]){return true;}

        // for(auto i:matrix){
        //     if (count(i.begin(), i.end(), target) >0){return true;}
        // }
        int j=0, i=m-1;
        while(j<n && i>=0){
            if(matrix[i][j]>target){i--;}
            else if(matrix[i][j]<target){j++;}
            else{
                return true;
            }
        }
        return false;

    }
};