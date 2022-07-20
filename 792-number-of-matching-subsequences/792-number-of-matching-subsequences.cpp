class Solution {
public:
    bool isSubSequence(string s1, string s2){
        int m = s1.length();        
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=0;i<m;i++){
            cout<<"\n"<<i<<"->";
            for(int j=0;j<n;j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    if(dp[i+1][j+1] == m) return true;
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
            cout<<dp[i+1][n]<<" ";
            if(i+1 != dp[i+1][n]) return false;
        }
        cout<<"\n";
        return false;
    }
    
    bool isSubSequence2(string s1, string s2){
        int m = s1.length();        
        int n = s2.length();
        int i=0, j=0;
        for(int i=0;i<n;i++){
            if(s2[i] == s1[j]){
                j++;
            }
            if(j == s1.size()) return true;
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int counter=0;
        unordered_map<string, int> mp;
        set<string> st;
        for(auto i:words){
            st.insert(i);
            mp[i]++;
        }
        vector<string> wordss(st.begin(), st.end());
        for(auto i:wordss){
            counter+= (isSubSequence2(i, s)) ? mp[i]:0;
        }
        return counter;
    }
};