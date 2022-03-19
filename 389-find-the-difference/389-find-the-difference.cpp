class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0;
        sort(s.begin(), s.end());        
        sort(t.begin(), t.end());
        while(i<s.length()){
            if(s[i]!=t[i]){
                return t[i];
            }
            i++;
        }
        return t[i];
    }
};