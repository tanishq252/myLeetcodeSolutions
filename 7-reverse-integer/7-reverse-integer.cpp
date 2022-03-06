class Solution {
public:
    int reverse(int x) {
        long long int rev = 0;
        long long int temp = x;
        long long int mod = 2147483647;        
        long long int modn = -2147483648;

        if(x == modn){return 0;}
        if(x<0){
            x = x*(-1);
        }
        while(x>0){
            rev = rev*10 + x%10;
            x = x/10;
        }
        if(rev>=mod){
            return 0;
        }else if(rev*-1<mod*-1){
            return 0;
        }
        if(temp<0){return (rev*-1);}
        else{return rev;}
        return 0;
    }
};