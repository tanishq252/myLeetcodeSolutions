class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int h=INT_MIN;
        double mxarea=0.00000;
        for(auto &i:points){
            for(auto &j:points){
                for(auto &k:points){
                    mxarea=max(mxarea, 0.5*(i[0]*j[1] - i[1]*j[0]+j[0]*k[1] - j[1]*k[0]+k[0]*i[1] - k[1]*i[0]));
                }
            }
        }
        
        return mxarea;
    }
};