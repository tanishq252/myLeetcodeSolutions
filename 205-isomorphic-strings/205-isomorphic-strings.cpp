class Solution {
public:

    bool isIsomorphic(string s, string t) {
        map<char, char> ms;        
        map<char, char> mt;
        for(int i=0;i<s.length();i++){
            if(ms.find(s[i]) == ms.end()){
                ms[s[i]] = t[i];
            }
            if(mt.find(t[i]) == mt.end()){
                mt[t[i]] = s[i];
            }
            if(ms[s[i]]!=t[i] or mt[t[i]]!=s[i]){
                return false;
            }
        }

        return true;
    }
};