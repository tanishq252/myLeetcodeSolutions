class Solution {
public:
    bool matchPattern(string s, string patternString){
        for(int i=0;i<s.length();i++){
            if(patternString[i]-'0' != count(s.begin(), s.end(), s[i])){
                return false;
            }
        }
        return true;
    }
    
    bool match2(string s, string pattern){
        for(int i=0;i<s.length()-1;i++){
            if(pattern[i]!=pattern[i+1]){
                if(s[i] == s[i+1]){
                    return false;
                }
            }else if(pattern[i]==pattern[i+1]){
                if(s[i] != s[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
//         string patternString = "";
//         for(auto &i:t){
//             patternString += to_string(count(t.begin(), t.end(), i));
//         } 
        
//         if(matchPattern(s, patternString)){
//             if(match2(s, t)){
//                 return true;
//             }
//         }
        map<char, char> ms;        
        map<char, char> mt;
        for(int i=0;i<s.length();i++){
            if(ms.find(t[i]) == ms.end()){
                ms[t[i]] = s[i];
            }
            if(mt.find(s[i]) == mt.end()){
                mt[s[i]] = t[i];
            }
            if(ms[t[i]]!=s[i] or mt[s[i]]!=t[i]){
                return false;
            }
        }

        return true;
    }
};