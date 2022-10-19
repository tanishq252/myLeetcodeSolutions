class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<vector<int>> v;
        for(auto &i:words){
            vector<int> f(26, 0);
            for(auto &j:i){
                f[j-'a']++;
            }
            v.push_back(f);
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1] == v[i]) words[i+1]="";
        }
        vector<string> ans;
        for(auto &i:words){
            if(i!="") ans.push_back(i);
        }
        return ans;
    }
};