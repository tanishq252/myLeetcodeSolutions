class Solution {
public:
    vector<vector<string>> ans;
    void recur(string s, int ind, vector<string> &vec){
        if(ind>=s.length()){
            ans.push_back(vec); return;
        }
        int i = ind;
        string s1 = s.substr(i,1);
        string s2 = s.substr(i,2);
        if(s1 != "0"){
            vec.push_back(s1);
            recur(s, i+1, vec);
            vec.pop_back();
        }
        if(s2[0] != '0' and s2.length()==2 and stoi(s2) <= 26){
            vec.push_back(s2);
            recur(s, i+2, vec);
        }
    }
    int numDecodings(string s) {
        // intuition is correct but takes too much time O(nlogn)
        // vector<string> vec;
        // recur(s, 0, vec);
        // return ans.size();
        int n = s.length();
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            if(s[i]!='0'){
                dp[i]+=dp[i+1];
            }
            if(i<n-1 and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7'))){
                dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};