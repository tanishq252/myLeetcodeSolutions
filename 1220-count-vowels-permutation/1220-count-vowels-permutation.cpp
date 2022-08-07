class Solution {
public:
    vector<long long> prevDp = {1LL,1LL,1LL,1LL,1LL};
    int mod = 1000000007;
    
    void possibleStrings(int n){
        vector<long long> dp(5, 0LL);
        dp[0] = (prevDp[1]%mod+prevDp[2]%mod+prevDp[4]%mod)%mod;
        dp[1] = (prevDp[0]%mod+prevDp[2]%mod)%mod;
        dp[2] = (prevDp[1]%mod+prevDp[3]%mod)%mod;
        dp[3] = (prevDp[2])%mod;
        dp[4] = (prevDp[2]%mod+prevDp[3]%mod)%mod;
        prevDp = dp;
    }
    
    int countVowelPermutation(int n) {
        n--;
        while(n--){
            possibleStrings(n);
        }
        long long ans = accumulate(prevDp.begin(), prevDp.end(), 0LL);
        return ans%mod;
    }
};