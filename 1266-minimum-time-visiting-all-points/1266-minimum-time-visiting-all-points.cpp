class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size() == 1){return max(points[0][0],points[0][1]);}
        int s1=0;
        for(int i=0;i<points.size()-1;i++){
                s1 = s1+max(abs(points[i][0]-points[i+1][0]),abs(points[i][1]-points[i+1][1]));             
        }
        return s1;

    }
};