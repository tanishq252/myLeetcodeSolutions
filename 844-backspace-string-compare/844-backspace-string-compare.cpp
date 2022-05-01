class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> s1;
        vector<char> s2;
        if(s==t){return true;}
        for(auto i:s){
            if(i=='#' && s1.size()>0){
                s1.pop_back();
            }else if(i!='#'){
                s1.push_back(i);
            }
        }
        for(auto i:t){
            if(i=='#' && s2.size()>0){
                s2.pop_back();
            }else if(i!='#'){
                s2.push_back(i);
            }
        }
        return s1==s2;
    }
};