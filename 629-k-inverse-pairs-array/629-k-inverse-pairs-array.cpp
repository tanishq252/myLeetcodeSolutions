class Solution {
    int v[1001][1001] = {};
    int mod = 1000000007;
public:
    int kInversePairs(int n, int k) {
        v[0][0] = 1;
        for(int i=1;i<=n;i++){
            long long x = 0;
            for(int j = 0;j<=k;j++){
                x+= v[i-1][j];
                if(j>=i){
                    x-=v[i-1][j-i];
                }
                v[i][j] = (v[i][j]+x)%mod;
            }
        }
        return v[n][k];

    }
};