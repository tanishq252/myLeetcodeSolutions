class Solution {
public:
    
    int removePalindromeSub(string s) {
        int ans = 0;
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i] == s[j]){
                i++;j--;
            }
            else if(s[i]!=s[j]){
                return 2;
            }
        }
        return 1;
    }
};