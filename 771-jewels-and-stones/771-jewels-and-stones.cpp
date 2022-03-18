class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = jewels.length();
        int m1 = stones.length();
        int c=0, i=0, j=0;
        map<char,int> m;
        for(int i=0;i<n;i++){
            m[jewels[i]] = 0;
        }
        for(int i=0;i<m1;i++){
            m[stones[i]]++;
        }
        for(int i=0;i<n;i++){
            c+=m[jewels[i]];
        }
        return c;
    }
};