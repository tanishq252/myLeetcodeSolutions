class Solution {
public:
    int subtractProductAndSum(int n) {
        long long int sum= 0;        
        long long int prod= 1;
        while(n>0){
            sum += n%10;
            prod *= n%10;
            n = n/10;
        }
        return prod-sum;
    }
};