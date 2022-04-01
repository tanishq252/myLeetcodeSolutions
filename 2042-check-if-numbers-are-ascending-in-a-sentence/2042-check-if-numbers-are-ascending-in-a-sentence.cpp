class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> v;
        string t = "";
        int i=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '&&t!=""){
                v.push_back(stoi(t));
                cout<<t<<"-";
                t = "";
            }else if(s[i]-'a'<0 && s[i]!=' '){
                t+=s[i];
            }
        }
        if(t!=""){
                v.push_back(stoi(t));
                cout<<t<<"-";
                t = "";
            }
        set<int> st (v.begin(), v.end());
        if(v.size()!=st.size()){return false;}
        vector<int> v1 = v;
        sort(v.begin(), v.end());
        return v==v1;
    }
};