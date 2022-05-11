class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1){return 5;}
        if(n==2){return 15;}
        vector<int> initialVec = {5,4,3,2,1};
        vector<vector<int>> v;
        v.push_back({1,1,1,1,1});
        v.push_back(initialVec);
        for(int i=1;i<=n;i++){
            int s = accumulate(v[i].begin(), v[i].end(), 0);
            vector<int> temp = {s};
            for(int j = 0;j<4;j++){
                temp.push_back(temp[j]-v[i][j]);
            }
            v.push_back(temp);
        }
        int fs = v[n][0];
        return fs;
        
    }
};