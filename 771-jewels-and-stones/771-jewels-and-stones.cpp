class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = jewels.length();        
        int c=0;
        for(int i=0;i<n;i++){
            c+= count(stones.begin(), stones.end(), jewels[i]);
        }
        return c;
    }
};