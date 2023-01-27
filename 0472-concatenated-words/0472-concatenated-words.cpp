class Solution {
public:
    set<string> st;
    set<string> ans;

    void recur(int i, string temp, vector<string> vec, string s){
        if(i>=s.length()) return;
        temp+=s[i];
        if(i==s.length()-1 and temp!=s and st.find(temp)!=st.end()){
            string t="";
            vec.push_back(temp);
            for(auto &j:vec) t+=j;
            if(t==s and vec.size()>=2) {ans.insert(t);}
            return;
        }
        if(st.find(temp)!=st.end()){
            vec.push_back(temp);
            string ss="";
            recur(i+1, ss, vec, s);
            vec.pop_back();
        }
        recur(i+1, temp, vec, s);
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &i:words) st.insert(i);
        for(int i=0;i<words.size();i++){
            string temp="";
            vector<string> vec;
            recur(0, temp, vec, words[i]);
        }
        return vector<string> (ans.begin(), ans.end());
    }
};