class Solution {
public:
    string getSmallestString(int n, int k) {
        // initialising string of length n with all 'a';
        string str(n,'a');
        
        k -= n;
        
        while( k > 0)
        {
            // turning rightmost digit , 'a' into 'z' ('a' + 25, or 'a' + k)
            // while k is positive.
            int j = min(25, k);
            str[--n] += j;
            k -= j;
        }
        
        return str;
        
    }
};