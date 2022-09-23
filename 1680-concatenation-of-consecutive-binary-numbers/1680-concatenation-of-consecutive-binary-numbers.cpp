class Solution {
public:
    long long int ans=0;
    int mod = 1000000007;
//     string addString(string &s, int x){
//         string bits = "";
//         long long int k = s.length();
//         while(x>0){
//             if(x%2==1) 
//             {
//                 ans= (ans%mod + (1<<k)%mod)%mod;
//                 ans%=mod;

//             }
//             bits += to_string(x%2);
//             k++;
//             x/=2;
//         }
//         return bits+s;
//     }
    
    int concatenatedBinary(int n) {
        int currentLength = 0;
        for(int i=1;i<=n;i++){
            if((i&(i-1)) == 0){
                currentLength++;
            }
            
            ans = (ans<<currentLength)%mod;
            ans += (i%mod);
        }
        return ans;
    }
};