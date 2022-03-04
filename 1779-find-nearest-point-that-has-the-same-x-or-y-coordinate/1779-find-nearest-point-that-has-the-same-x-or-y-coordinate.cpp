class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<vector<int>> manDistances;
        vector<int> indices;
        for(int i=0;i<points.size();i++){
            if(points[i][0] == x || points[i][1] == y){
                manDistances.push_back(points[i]);
                indices.push_back(i);
            }
        }
        int minMD = INT_MAX;
        int index = 0;
        for(int i=0;i<manDistances.size();i++){
            if(abs(x - manDistances[i][0])+abs(y - manDistances[i][1]) < minMD){
                minMD = abs(x - manDistances[i][0])+abs(y - manDistances[i][1]);
                index = i;
            }
        }
        return (manDistances.size()==0)? -1 : indices[index];
    }
};