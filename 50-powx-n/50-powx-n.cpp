class Solution {
public:
    double myPow(double x, int n) {
        double ans = x;
        if((x)==1.00000){
            return x;
        }if( x==-1.00000){
            return n%2==0 ? 1.00000 : x;
        }
        if(n==0){
            return 1.00000;
        }
        bool flag = (n<0) ? true:false;
        n = abs(n);
        n--;
        while(n--){
            ans*=x;
            if(ans>100000.00000){
                return 0.00000;
            }
        }
        if(flag){
            
            return 1/ans;
        }
        return ans;
    }
};