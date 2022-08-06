class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = needle.length();
        int hl = haystack.length();
        if(l > hl) return -1;
        if(needle==haystack) return 0;
        for(int i=0;i<=hl-l;i++){
            string subst = haystack.substr(i, l);
            if(subst == needle) return i;
        }
        return -1;
    }
};