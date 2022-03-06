class Solution {
public:
    int numberOfSteps(int n) {
        int c = 0;
        while(n>0){
            n = (n%2==0)?n/2:n-1;
            c++;
        }
        return c;
    }
};