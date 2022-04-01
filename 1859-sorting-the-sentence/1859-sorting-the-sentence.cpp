class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string>> v;
        string t = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){continue;}
            else if(s[i]-'a'<=-40){
                v.push_back(make_pair(s[i]-'0', t));
                t = "";
            }
            else{t+=s[i];}
        }
        sort(v.begin(), v.end());
        string ans;
        for(int i=0;i<v.size();i++){
            ans+= v[i].second;
            if(i!=v.size()-1){ans+=" ";}
        }
        return ans;
    }
};