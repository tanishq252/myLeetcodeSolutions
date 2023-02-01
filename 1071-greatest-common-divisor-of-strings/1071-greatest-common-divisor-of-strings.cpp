class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans="", ss="";
        if(str1 == str2) return str1;
        if(str2.length() > str1.length()){
            swap(str1,str2);
        }
        for(auto &i:str2){
            ss+=i;
            int l = ss.length(), flag=0;
            for(int j=0;j<str1.length();j+=l){
                if(str1.substr(j,l) != ss){
                    flag = 1;
                    break;
                }
            }
            for(int j=0;j<str2.length();j+=l){
                if(str2.substr(j,l) != ss){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                if(ans.length() < ss.length()){
                    ans = ss;
                }
            }
        }
        
        return ans;
    }
};