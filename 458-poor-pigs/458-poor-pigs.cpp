class Solution {
public:
    int findMaxFactor(int tests, int target){
        int c=0;
        int k = 1;
        while(target > k){
            cout<<c<<" ";
            k*=tests;
            c++;
        }
        return c;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        return findMaxFactor((minutesToTest/minutesToDie)+1, buckets);
    }
};