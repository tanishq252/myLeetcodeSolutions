class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1){return 5;}
        vector<vector<int>> v;
        v.push_back({1,1,1,1,1});
        for(int i=0;i<=n;i++){
            int s = accumulate(v[i].begin(), v[i].end(), 0);
            vector<int> temp = {s};
            for(int j = 0;j<4;j++){
                temp.push_back(temp[j]-v[i][j]);
            }
            v.push_back(temp);
        }
        return v[n][0];
    }
};