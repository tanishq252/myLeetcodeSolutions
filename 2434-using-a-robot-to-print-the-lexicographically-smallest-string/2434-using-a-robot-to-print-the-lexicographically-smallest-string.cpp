class Solution {
public:
    char lowestChar(vector<int> &f){
        for(int i=0;i<26;i++){
            if(f[i]>0) return i+'a';
        }
        return 'z';
    }
    string robotWithString(string s) {
        string ans="";
        stack<int> t;
        vector<int> v(26, 0);
        for(auto &i:s) v[i-'a']++;
        for(auto &i:s){
            t.push(i);
            v[i-'a']--;
            while(t.size()>0 and t.top()<=lowestChar(v)){
                ans+=t.top();
                t.pop();
            }
        }
        return ans;
    }
};