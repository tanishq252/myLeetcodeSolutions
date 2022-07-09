class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size(),lower=0,upper; 
        vector<bool> dp(n,false);
        dp[0]=true;
     
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            upper=min(i+maxJump,n-1);   
           for(int j=max(lower,i+minJump);j<=upper;j++) 
            {if(s[j]=='0') dp[j]=true;}
           lower=upper+1; 
         }
        return dp[n-1];
    }
};