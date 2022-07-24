class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> rows = grid;
        
        //transpose of the given grid so we convert rows to columns
        for(int i=0; i<grid.size(); i++){
            for(int j=0;j<i;j++){
                swap(grid[i][j], grid[j][i]);
            }
        }
        
        int pairs = 0;
        
        //traverse through the rows to check whether similar vector is present in transpose of given matrix using the stl methods
        for(auto i:rows){
            for(auto j:grid){
                pairs+=(i==j)?1:0;
            }
        }
        
        
        
        return pairs;
    }
};