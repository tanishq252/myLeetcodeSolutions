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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string patternString = "";
        for(auto &i:pattern){
            patternString += to_string(count(pattern.begin(), pattern.end(), i));
        }
        vector<string> ans;
        cout<<patternString;
        for(auto &s:words){
            if(matchPattern(s, patternString) and match2(s, pattern)){
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};