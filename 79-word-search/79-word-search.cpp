class Solution {
public:
    
    bool dfs(int i, int j, vector<vector<char>>& board, string word){
        if(word.size()==0) return true;
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!=word[0]) return false;
        char temp = board[i][j];
        //current character should not be revisited
        board[i][j] = '_';
        string nextString = word.substr(1); // string starting from index 1
        
        //check for further neighbors if they can continue the string
        bool ans = dfs(i-1, j,  board, nextString) or dfs(i+1, j,  board, nextString) or dfs(i, j+1,  board, nextString) or dfs(i, j-1, board, nextString);
        //backtrack
        board[i][j] = temp;
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(i, j, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
    
    // 77/84 test cases passed
//     bool exists = false;
    
//     void append(int i, int j, vector<vector<char>> &board, string &word,int index, vector<vector<bool>> &visited){
//         if(index==word.size()){
//             exists = true;return;}
//         if(i>0){
//             if(board[i-1][j] == word[index] and !visited[i-1][j]){
//                 visited[i-1][j] = true;
//                 append(i-1, j, board, word, index+1, visited);
//             }
//         }
//         if(i<board.size()-1){
//             if(board[i+1][j] == word[index] and !visited[i+1][j]){
//                 visited[i+1][j] = true;
//                 append(i+1, j, board, word, index+1, visited);
//             }
//         }
//         if(j>0){
//             if(board[i][j-1] == word[index] and !visited[i][j-1]){
//                 visited[i][j-1] = true;
//                 append(i, j-1, board, word, index+1, visited);
//             }
//         }
//         if(j<board[0].size()-1){
//             if(board[i][j+1] == word[index] and !visited[i][j+1] ){
//                 visited[i][j+1] = true;
//                 append(i, j+1, board, word, index+1, visited);
//             }
//         }
//     }
    
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false) );
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 if(board[i][j] == word[0] and !visited[i][j]){
//                     visited[i][j] = true;
//                     append(i, j, board, word, 1, visited);
//                     visited = vector<vector<bool>> (board.size(), vector<bool>(board[0].size(), false) );
//                 }
//                 if(exists){
//                     break;
//                 }
//             }
//             if(exists){
//                     break;
//                 }
//         }
//         return exists;
//     }
};