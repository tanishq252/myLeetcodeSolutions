class Solution {
public:
    
    // 170/178 cases passed
    map<string, int> mp;
    int strL = 0;
    
    
    bool checkSubstr(string s, vector<string> words){
        int i=0;map<string, int> temp;
        int l = words[0].length();
        while(i<s.length()){
            temp[s.substr(i, l)]++;
            i+=l;
        }
        return mp==temp;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        map<string, int> mp2;
        int l = words[0].length();
        int strlen=0,ind=0;
        for(auto i:words){
            strlen+=i.length();
            mp2[i]++;
        }
        strL = strlen;
        if(strlen>s.length()) return {};
        mp = mp2;
        for(int i=0;i<=s.length()-strlen;i++){
            if(checkSubstr(s.substr(i, strlen), words)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    
    // 153/178 cases passed
//     map<string, int> mp;
//     int strL=0;
//     bool wordBreak(string s, vector<string> &words){
//         vector<int> dp(s.length()+1, 0);
//         dp[0]=1;
//         for(int i=1;i<=s.length();i++){
//             for(int j=i-1;j>=0;j--){
//                 if(dp[j]){
//                     string str = s.substr(j, i-j);
//                     if(count(words.begin(), words.end(), str) > 0 and mp[str]>0){
//                         dp[i] = 1;mp[str]--;
//                     }
//                 }
//             }
//         }
//         return dp[s.length()]==1 and s.length() == strL;
//     }
//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> ans;
//         map<string, int> mp2;
//         int strlen=0,ind=0;
//         for(auto i:words){
//             strlen+=i.length();
//             mp2[i]++;
//         }
//         strL = strlen;
//         mp = mp2;
//         for(int i=0;i<s.length();i++){
//             if(wordBreak(s.substr(i, strlen), words)){
//                 ans.push_back(i);
//             }
//             mp = mp2;
            
//         }
//         return ans;
//     }
};