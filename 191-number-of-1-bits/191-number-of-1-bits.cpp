class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while(n>0){
            c+= n%2==1 ? 1:0;
            n = n/2;
        }
        return c;
    }
};