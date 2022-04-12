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
        int c0 = count(neighbors.begin(),neighbors.end(),0);
        
        if(board[i][j]==1){
            if(c1 < 2){
                dumboard[i][j] = 0;
            }else if(c1==2 || c1==3){
                dumboard[i][j] = 1;
            }
            else if(c1>3){dumboard[i][j] = 0;}
        }else if(board[i][j] == 0){
            if(c1==3){
                dumboard[i][j] = 1;
            }
        }
        
        cout<<c1<<" ";

    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> dumboard;
        
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<m;j++){
                v.push_back(0);
            }
            dumboard.push_back(v);
        }
        
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