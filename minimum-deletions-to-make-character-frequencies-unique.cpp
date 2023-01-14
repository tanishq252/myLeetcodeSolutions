// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> charFreq(26, 0);
        unordered_map<char, int> mp;
        vector<int> v;
        int ans = 0;
        for(auto &i:s){
            mp[i]++;
        }
        for(auto &i:mp) v.push_back(i.second);
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==0) {ans+=v[i+1];v[i+1]=0;}
            else if(v[i]==v[i+1]){
                ans ++;
                v[i+1]--;
            }else if(v[i+1] > v[i]){
                ans++;
                ans+=(v[i+1]-v[i]);
                v[i+1]=v[i]-1;
            }

        }
        return ans;
    }
};