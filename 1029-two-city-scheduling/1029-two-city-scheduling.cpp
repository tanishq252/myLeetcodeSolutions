class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int s=0;
        int sumA = 0;
        vector<int> v;
        for(auto i:costs){
            sumA+=(i[0]);
            v.push_back(i[1]-i[0]);
        }
        sort(v.begin(), v.end());
        cout<<v[0]<<v[1];
        s = accumulate(v.begin(), v.begin()+(v.size()/2), sumA);
        return s;
    }
};