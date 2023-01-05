// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        int ans=0;
        int arrowPos = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0] <= arrowPos) continue;
            ans++;
            arrowPos = points[i][1];
        }
        return ans+1;
    }
};