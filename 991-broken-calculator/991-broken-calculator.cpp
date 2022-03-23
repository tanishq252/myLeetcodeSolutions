class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int c=0;
        while(target>startValue){
            target = (target%2==0) ? target/2 : target+1;
            c++;
        }
        cout<<target;
        return c+startValue-target;
    }
};