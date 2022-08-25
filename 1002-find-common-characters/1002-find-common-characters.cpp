class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX);
        vector<string> ans;
        string s = "abcdefghijklmnopqrstuvwxyz";
        // ans.push_back(string({'c'}));
        int n = words.size();
        for(auto &s:words){
            vector<int> freq1(26, 0);
            for(auto c:s){
                freq1[c-'a']++;
            }
            for(int i=0;i<26;i++){
                freq[i] = min(freq1[i], freq[i]);
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<freq[i];j++){
                ans.push_back({s[i]});
            }
        }
        return ans;
    }
};