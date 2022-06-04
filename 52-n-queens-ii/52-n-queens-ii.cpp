class Solution {
public:
    int ans =0;
    
    bool isSafe(vector<vector<int>> &board, int row, int col){
        int n = board.size();
        if(row>=n or col>=n) return false;
        
        for(int i=0;i<col;i++){
            if(board[row][i]) return false;
        }
        
        for(int i=row, j=col;i>=0 and j>=0;i--,j--){
            if(board[i][j]) return false;
        }
        
        for(int i=row, j=col;i<n and j>=0;i++,j--){
            if(board[i][j]) return false;
        }
        
        return true;
    }
    
    bool NQsolved(vector<vector<int>> &board, int col){
        int n = board.size();
        if(col>=n) return true;
        
        for(int i=0;i<n;i++){
            if(isSafe(board, i, col)){
                board[i][col] = 1;                
                if(NQsolved(board, col+1)) ans++;
                board[i][col] = 0;
            }
        }
        
        return false;
    }
    
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int> (n, 0));
        NQsolved(board, 0);
        return ans;
    }
};