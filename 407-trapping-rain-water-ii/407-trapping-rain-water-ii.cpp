class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0,-1}, {0, 1}, {1,0}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> boundary;
        
        // bondaries along with x axis
        for(int i=0;i<m;i++){
            // push the boundary values for each vector
            boundary.push({heightMap[i][0], i, 0});            
            visited[i][0] =  true;
            boundary.push({heightMap[i][n-1], i, n-1});
            visited[i][n-1] =  true;
        }
        
        // bondaries along with y axis
        for(int i=0;i<n;i++){
            // push the boundary values for each vector
            boundary.push({heightMap[0][i], 0, i});            
            visited[0][i] =  true;
            boundary.push({heightMap[m-1][i], m-1, i});
            visited[m-1][i] =  true;
        }
        
        int ans = 0;
        
        // performing bfs on the internal part of the container
        while(!boundary.empty()){
            vector<int> current = boundary.top();
            boundary.pop();
            
            for(auto i:directions){
                int x = i[0]+current[1];
                int y = i[1]+current[2];
                
                if(x>=0 and x<m and y>=0 and y<n and !visited[x][y]){
                    visited[x][y] = true;
                    ans+= max(current[0]-heightMap[x][y], 0);
                    boundary.push({max(current[0], heightMap[x][y]), x, y});
                }
            }
        }
        return ans;
        
    }
};