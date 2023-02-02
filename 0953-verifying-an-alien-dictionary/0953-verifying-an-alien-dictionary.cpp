class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> mp;
        for(int i=0;i<26;i++){
            mp[order[i]] = 'a'+i;
        }
        vector<string> v,vv;
        for(auto i:words){
            string s="";
            for(auto j:i){
                s += mp[j];
            }
            v.push_back(s);
        }
        vv=v;
        sort(v.begin(),v.end());
        return v==vv;
    }
};