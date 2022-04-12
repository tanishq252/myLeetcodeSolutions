class Solution {
public:

    void updateEle(vector<vector<int>>& dumboard, vector<vector<int>>& board,int i, int j){
        int n = board.size()-1;
        int m = board[0].size()-1;
        vector<int> neighbors;
        if(i-1>=0&&j-1>=0&&i-1<=n&&j-1<=m){neighbors.push_back(board[i-1][j-1]);}        
        if(i-1>=0&&j+1>=0&&i-1<=n&&j+1<=m){neighbors.push_back(board[i-1][j+1]);}        
        if(i-1>=0&&j>=0&&i-1<=n&&j<=m){neighbors.push_back(board[i-1][j]);}
        if(i+1>=0&&j-1>=0&&i+1<=n&&j-1<=m){neighbors.push_back(board[i+1][j-1]);}        
        if(i+1>=0&&j+1>=0&&i+1<=n&&j+1<=m){neighbors.push_back(board[i+1][j+1]);}        
        if(i+1>=0&&j>=0&&i+1<=n&&j<=m){neighbors.push_back(board[i+1][j]);}
        if(i>=0&&j-1>=0&&i<=n&&j-1<=m){neighbors.push_back(board[i][j-1]);}        
        if(i>=0&&j+1>=0&&i<=n&&j+1<=m){neighbors.push_back(board[i][j+1]);}        
        int c1 = count(neighbors.begin(),neighbors.end(),1);  
        dumboard[i][j] = (board[i][j]==1)?((c1==2 || c1==3)?1:0):(c1==3)?1:0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> dumboard(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                updateEle(dumboard, board, i, j);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = dumboard[i][j];
            }
        }
        
    }
};