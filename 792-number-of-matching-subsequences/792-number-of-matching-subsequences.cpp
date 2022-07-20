class Solution {
public:
    
    // function using dynamic programming to check the subsequence of strings
    // as there are 2 loops the time complexity is o(n^2) hence it gives TLE
    bool isSubSequence(string s1, string s2){
        int m = s1.length();        
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    if(dp[i+1][j+1] == m) return true;
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
            if(i+1 != dp[i+1][n]) return false;
        }
        return false;
    }
    
    // this is a simple logic to check subsequence with simple traversal
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
        
        //as there can be a probablity of having multiple identical words which increases number of operations
        // hence map mp stores frequency of all words and set is used to store unique words
        unordered_map<string, int> mp;
        for(auto i:words){
            mp[i]++;
        }
        
        //further using stl we convert the set to vector for traversing unique words 
        //if a word is subsequence we will add it's frequency to counter which keeps track of all sebsequences
        for(auto i:mp){
            counter+= (isSubSequence2(i.first, s)) ? i.second:0;
        }
        return counter;
    }
};