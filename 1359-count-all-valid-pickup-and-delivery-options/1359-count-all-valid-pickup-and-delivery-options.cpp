class Solution {
public:
    int countOrders(int n) {
        int mod = 1000000007;
        long long int f = 1;
        
        for(int i=1;i<=n;i++){
            f = ((f%mod)*i)%mod;
            f = f%mod;
        }
        
        long long int prod = 1;
        for(int i=1;i<=n;i++){
            prod = ((prod%mod)*(2*i-1))%mod;
            prod = prod%mod;
        }
        
        return ((prod%mod)*(f%mod))%mod;
    }
};