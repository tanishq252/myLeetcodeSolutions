class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> v = {{1}, {1,1}};
        if(numRows==2) return v;
        for(int i=2;i<numRows;i++){
            v.push_back({});
            v[i].push_back(1);
            for(int j = 1;j<i;j++){
                v[i].push_back(v[i-1][j]+v[i-1][j-1]);
            }
            v[i].push_back(1);
        }
        return v;
    }
};