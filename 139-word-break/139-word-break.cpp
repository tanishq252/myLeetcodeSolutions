class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, 0);
        // as we have to find from first character
        dp[0] = 1;
        //this is nothing but length of sub strings
        for(int i=1;i<=s.length();i++){
            //positions of start of the substrings 
            for(int j = i-1;j>=0;j--){
                // if the substring till this posn is existing then we have to proceed
                if(dp[j]){
                    // length is i-j and initial position is j
                    string word = s.substr(j, i-j);
                    if(count(wordDict.begin(), wordDict.end(), word) > 0){
                        dp[i] = 1; // mark that till ith posn there is a substr present in dictionary
                        break;
                        
                    }
                }
            }
        }
        for(auto &i:dp){
            cout<<i<<" ";
        }
        
        return dp[s.length()]==1;
        
    // 38/45 test cases
    //     bool falg = true;
    //     int i=0;
    //     sort(wordDict.begin(), wordDict.end(), [](string a, string b){
    //         return a.length() < b.length();
    //     });
    //     while(s.length()){
    //         bool found = false;
    //         for(auto &word:wordDict){
    //             if(s.substr(i, word.length()) == word){
    //                 cout<<word<<" ";
    //                 i+=word.length();
    //                 if(i==s.length()){
    //                     return true;
    //                 }
    //                 found = true;
    //             }
    //         }
    //         if(!found) return false;
    //     }
    //     return true;
    }
};