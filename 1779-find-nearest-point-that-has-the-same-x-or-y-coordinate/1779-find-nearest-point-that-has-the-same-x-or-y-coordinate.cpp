class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<vector<int>> manDistances;
        int minMD = INT_MAX;
        int index = -1;
        for(int i=0;i<points.size();i++){
            if(points[i][0] == x || points[i][1] == y){
                if(abs(x - points[i][0])+abs(y -points[i][1]) < minMD){
                minMD = abs(x - points[i][0])+abs(y - points[i][1]);
                index = i;
            }
            }
        }
        return (index == -1)? -1 : index;
    }
};