class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, vector<int>>> v;
        for(auto &i:points){
            int d = (i[0]*i[0])+(i[1]*i[1]);
            v.push_back({sqrt(d), i});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};