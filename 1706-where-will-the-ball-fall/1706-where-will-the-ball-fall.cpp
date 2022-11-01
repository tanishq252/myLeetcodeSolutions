class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for(int i=0;i<grid[0].size();i++) ans[i] = findPath(0, i, grid);
        return ans;
    }
    
    int findPath(int row, int col, vector<vector<int>> &grid){
        if(row == grid.size()) return col;
        int nextCol = col+grid[row][col];
        if(nextCol<0 or nextCol>=grid[0].size() or grid[row][col]!=grid[row][nextCol]) return -1;
        return findPath(row+1, nextCol, grid);
    }
};