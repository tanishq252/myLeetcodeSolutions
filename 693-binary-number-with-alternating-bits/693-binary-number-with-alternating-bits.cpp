class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n==1){return 1;}
        int prev = n%2;
        n/=2;
        int j;
        while(n>0){
            j = n%2;
            n/=2;
            if(prev==j){return false;}
            prev = j;
        }
        return true;
        
    }
};