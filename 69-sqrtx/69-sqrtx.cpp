class Solution {
public:
    int mySqrt(int x) {
        if(x==1){return 1;}
        long long int j = 1;
        while(j<=x/2){
            j++;
            if(j*j > x){return j-1;}
        }
        return 0;
    }
};