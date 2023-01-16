class Solution {
public:

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int> (n));       
        for(auto &i:queries){
            // updateQuery(i[0],i[]);
            ans[i[0]][i[1]]++;
            if(i[2]+1<n) ans[i[2]+1][i[1]]--;            
            if(i[2]+1<n and i[3]+1<n) ans[i[2]+1][i[3]+1]++;
            if(i[3]+1<n) ans[i[0]][i[3]+1]--;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[j][i]+=ans[j-1][i];
            }
        }
        return ans;
    }
};