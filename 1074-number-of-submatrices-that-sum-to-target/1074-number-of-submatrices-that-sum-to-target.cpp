class Solution {
public:
    bool checkSum(int row, int col, int target, vector<vector<int>> &mat){
        return false;
        
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int counter=0;
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> temp(r+1, vector<int> (c, 0));
        
        //this iteration for storing prefix sum
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temp[i+1][j] = temp[i][j]+matrix[i][j];
            }
        }
        
        //this iteration is to check all the sub matrices and their sums
        
        //iteration through all the rows
        for(int i=0;i<r;i++){
            //iteration through all the following rows from current row
            // i+1 since we have considered an extra row for prefix sum
            for(int j=i+1;j<=r;j++){
                
                //iteration through all the columns
                for(int x=0;x<c;x++){
                    //variable that consists sum of current sub matrix
                    int sum = 0;
                    
                    //iteration through all the columns following current column
                    for(int y=x;y<c;y++){
                        sum+= (temp[j][y] - temp[i][y]);
                        counter += (sum == target) ? 1:0;
                    }
                }

            }
        }
        
        return counter;
    }
};