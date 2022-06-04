class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(vector<string> &board, int row, int col){
        int n=board.size(); 
        if(row>=n or col>=n ) return false;
        //left side of the row
        for(int i=0;i<col;i++){
            if(board[row][i] == 'Q') return false;
        }
        //upper left diagonal
        for(int i= row, j=col; i>=0 and j>=0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        //lower left diagonal
        for(int i=row,j=col;i<n and j>=0;i++,j--){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    
    bool NQsolved(vector<string> &board, int col){
        int n = board.size();
        
        // if number of columns exceed the current number
        if(col>=n) return true;
        
        // traverse through all the rows, column by column filling it from left side
        for(int i=0;i<n;i++){
            if(isSafe(board, i, col)){
                board[i][col] = 'Q';
                
                if(NQsolved(board, col+1)){
                    ans.push_back(board);
                }
                
                board[i][col] = '.';
            }
        }
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, "");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i]+=".";
            }
        }
        
        NQsolved(board, 0);
        
        return ans;
        
        
    }
};