class Solution {
public:
    vector<vector<string>> ans;
    set<vector<string>> st;
    bool isPal(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]) {i++;j--;}
            else return false;
        }
        return true;
    }

    void recur(int i, string s, string temp, vector<string> v){
        temp+=s[i];
        if(i>=s.length() and temp!="") {
            if(v.size()>0){
                if(v.back()[v.back().length()-1] == s[s.length()-1]){
                    string su="";
                    for(auto &i:v){su+=i;}
                    if(su==s and st.find(v)==st.end())  {st.insert(v); ans.push_back(v);}
                }
            }
            
            return;
        }
        string t="";
        if(isPal(temp) and temp!="") {
            v.push_back(temp);
            recur(i+1, s, t, v);
            v.pop_back();
            recur(i+1, s, temp, v);
        }else{
            recur(i+1,s,temp,v);
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        string ss="";
        for(auto &i:s){
            ss=i;
            v.push_back(ss);
        }
        st.insert(v);
        ans.push_back(v);
        ss="";
        v={};
        recur(0, s, ss, v);

        return ans;
    }
};