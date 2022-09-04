class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(auto i:words){
            mp[i]++;
        }
        vector<pair<int,string>> v;
        for(auto i:mp){
            v.push_back({-i.second, i.first});
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for(auto i:v){
            if(k==0) break;
            ans.push_back(i.second);k--;
        }
        
        return ans;
    }
};