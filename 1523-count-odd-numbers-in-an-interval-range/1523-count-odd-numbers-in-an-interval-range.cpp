class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==1 && high%2==1){
            return((high-low)/2)+1;
        }
        return (high-low+1)/2;
    }
};