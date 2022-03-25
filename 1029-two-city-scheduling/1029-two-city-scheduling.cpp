class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sumA = 0;
        vector<int> v;
        for(auto i:costs){
            sumA+=(i[0]);
            v.push_back(i[1]-i[0]);
        }
        sort(v.begin(), v.end());
        int s = accumulate(v.begin(), v.begin()+(v.size()/2), sumA);
        return s;
    }
};