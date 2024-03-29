class Solution {
public:
//     bool isPrime(int n){
//         int c=0;
//         for(int i=1;i<=n/2;i++){
//             c+= (n%i==0)?1:0;
//         }
//         return (c==1)?true:false;
//     }
    
//     int numberofones(int n){
//         int c=0;
//         while(n>0){
//             c+= (n%2==1)?1:0;
//             n/=2;
//         }
//         return c;
//     }
    
    int countPrimeSetBits(int left, int right) {
        int c=0;
        // we have maximum 32 bits 
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
        
        for(int i=left;i<=right;i++){
            // int m = numberofones(i);
            // if(isPrime(m)){c++;}
            c+= count(primes.begin(), primes.end(), (bitset<32>(i)).count());

        }
        return c;
    }
};