class Solution {
public:
    	int recur(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){
		// since the given index consists 1 so we have to return the number itself in case it’s adjacent sides are having values 0
		int sum = 1;
		// mark the current element as visited so that it won’t be considered again, and recursion takes place in a desired way
		visited[i][j] = true;

		// following are the four conditions to keep on checking adjacent indices and call the recursive function so that we can get the maximum number of adjacent indices as per problem statement
		if(i != grid.size()-1){
			if(grid[i+1][j]=='1' and !visited[i+1][j]){
				sum += recur(i+1, j, grid, visited);
			}
		}
		if(i!=0){
			if(grid[i-1][j]=='1' and !visited[i-1][j]){
				sum += recur(i-1, j, grid, visited);
			}
		}
		if(j != grid[0].size()-1){
			if(grid[i][j+1]=='1' and !visited[i][j+1]){
				sum += recur(i, j+1, grid, visited);
			}
		}
		if(j!=0){
			if(grid[i][j-1]=='1' and !visited[i][j-1]){
				sum += recur(i, j-1, grid, visited);
			}
		}

		// returning the final sum or maximum sum of areas for given index
		return sum;
	}
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int numberOfIslands = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size(); j++){
                if(grid[i][j] == '1' and !visited[i][j]){
                    int s = recur(i, j, grid, visited);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
        
    }
};