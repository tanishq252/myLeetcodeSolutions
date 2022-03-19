class Solution {
public:
    int sumBase(int n, int k) {
        int s=0;
        while(n>0){
            s+= (n%k);
            n/=k;
        }
        return s;
    }
};