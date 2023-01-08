// https://leetcode.com/problems/max-points-on-a-line/submissions/873942237/
// maths, hashmap, logic

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx=INT_MIN;
        unordered_map<double, int> mp;
        double slope = 0.00000;
        int vertical=0, horizontal=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(points[i][1]==points[j][1]){
                        horizontal++;
                        mx = max(mx, horizontal+1);

                    }else if(points[i][0]==points[j][0]){
                        vertical++;
                        mx = max(mx, vertical+1);
                    }
                    else{
                        slope = (double)( points[i][1]-points[j][1]) / ( points[i][0]-points[j][0]);
                        cout<<slope<<" ";
                        mp[slope]++;
                        mx = max(mx, mp[slope]+1);
                    }
                }
            }
            mp.clear();
            horizontal=0;
            vertical=0;
        }
        return mx==INT_MIN ? 1:mx;
    }
};