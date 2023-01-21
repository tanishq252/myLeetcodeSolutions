class Solution {
public:
    vector<vector<string>> ans;

    void recur(int i, string s, vector<string> vec){
        if(vec.size()==4 and i==s.length()){
            ans.push_back(vec);
            return;
        }
        int n = s.length();
        if(i>=n) return;
        if(s[i]=='0'){
            string ss = "";
            ss = s[i];
            vec.push_back(ss);
            recur(i+1, s, vec);
        }
        else{
            string ss = "";
            ss = s[i];
            i++;
            vec.push_back(ss);
            recur(i, s, vec);
            vec.pop_back();
            if(i<n){
                ss+=s[i];i++;
                if(stoi(ss)<=255){
                    vec.push_back(ss);
                    recur(i,s, vec);
                    vec.pop_back();
                }
            }
            if(i<n){
                ss+=s[i++];
                if(stoi(ss)<=255){
                    vec.push_back(ss);
                    recur(i,s, vec);
                    vec.pop_back();
                }
            }
        }
        
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12 or s.length()<4) return {};
        if(s.length()==4){
            string ss="";
            for(int i=0;i<3;i++){
                ss+=s[i];ss+=".";
            }
            ss+=s[3];
            return {ss};
        }
        string ss="";
        vector<string> vec;
        recur(0, s, vec);
        vec={};
        for(auto &i:ans){
            string a = "";
            for(int j=0;j<3;j++){
                a+=i[j];
                a+=".";
            }
            a+=i[3];
            vec.push_back(a);
        }
        return vec;
    }

};