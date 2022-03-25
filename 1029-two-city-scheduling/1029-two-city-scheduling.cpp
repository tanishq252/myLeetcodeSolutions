class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> v;
        for(int i=0;i<costs.size();i++){
            v.push_back(make_pair(costs[i][0]-costs[i][1], i ));
        }
        sort(v.begin(), v.end());
        int s=0;
        for(int i=0;i<v.size()/2;i++){
            s+=(costs[v[i].second][0]);
        }
        for(int i=v.size()/2;i<v.size();i++){
            s+=(costs[v[i].second][1]);
        }
        return s;
    }
};