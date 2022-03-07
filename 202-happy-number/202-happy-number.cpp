class Solution {
public:
    
    int getNextNum(int n){
        int total = 0;
        while(n>0){
            total+=((n%10)*(n%10));
            n = n/10;
        }
        return total;
    }
    
    bool isHappy(int n) {
         set<int> collections;
        while(n!=1 && !(collections.find(n)!=collections.end())){
            collections.insert(n);
            n = getNextNum(n);
        }
        return n==1;
    }
};