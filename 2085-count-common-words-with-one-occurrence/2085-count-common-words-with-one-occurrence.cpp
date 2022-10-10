class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> mp,mp2;
        int ans=0;
        for(auto &i:words1){
            mp[i]++;
        }
        for(auto &i:words2){
            mp2[i]++;
        }
        for(auto &i:mp){
            if(mp2[i.first] == 1 and i.second == 1) ans++;
        }
        return ans;
    }
};