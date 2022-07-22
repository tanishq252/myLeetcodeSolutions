class Solution {
public:
    bool isBoundary = false;
    	int recur(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
		// since the given index consists 1 so we have to return the number itself in case it’s adjacent sides are having values 0
		int sum = 1;
		// mark the current element as visited so that it won’t be considered again, and recursion takes place in a desired way
		visited[i][j] = true;

		// following are the four conditions to keep on checking adjacent indices and call the recursive function so that we can get the maximum number of adjacent indices as per problem statement
		if(i==0 || i == grid.size() - 1 || j==0 || j == grid[0].size()-1){
            isBoundary = true;
            return sum;
        }
        else{
        if(i != grid.size()-1){
			if(grid[i+1][j]==1 and !visited[i+1][j]){
				sum += recur(i+1, j, grid, visited);
			}
		}
		if(i!=0){
			if(grid[i-1][j]==1 and !visited[i-1][j]){
				sum += recur(i-1, j, grid, visited);
			}
		}
		if(j != grid[0].size()-1){
			if(grid[i][j+1]==1 and !visited[i][j+1]){
				sum += recur(i, j+1, grid, visited);
			}
		}
		if(j!=0){
			if(grid[i][j-1]==1 and !visited[i][j-1]){
				sum += recur(i, j-1, grid, visited);
			}
		}}

		// returning the final sum or maximum sum of areas for given index
		return sum;
	}
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> ( grid[0].size() , 0));
        int ans =0;
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                if(!visited[i][j] and grid[i][j] == 1){
                    int s = recur(i, j, grid, visited);
                    if(isBoundary){
                        isBoundary = false;
                    }else{
                        
                        cout<<i<<" "<<j<<"->"<<s<<"\n";
                        ans+=s;
                    }
                }
            }
        }
        return ans;
        
    }
};