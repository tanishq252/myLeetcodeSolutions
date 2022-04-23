class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        if(s.length()%k!=0){
            for(int i=0;i<(s.length()%k);i++){
            s+=fill;
        }
        }
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            string ss = "";
            int x = k;
            while(x--){
                ss+=s[i++];
            }
            ans.push_back(ss);
            x=k;
            i--;
        }
        return ans;
    }
};