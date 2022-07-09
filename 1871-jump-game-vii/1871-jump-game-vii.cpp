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
        // vector<int> dp(s.length(), false);
        // int upper, lower=0;
        // if(s[s.length() - 1]!='0'){
        //         return false;
        //     }
        // dp[0] = true;
        // for(int i=0;i<s.length();i++){
        //     upper = (s.length()-1 > i+maxJump) ? i+maxJump:s.length()-1;
        //                 cout<<lower<<" "<<upper<<"\n";
        //     lower = (i+minJump>lower)?i+minJump:lower;
        //     if(upper<lower) break;
        //     if(dp[i]){
        //         for(int j =lower;j<=upper;j++){
        //             if(s[j] == '0'){
        //                 dp[j] = true;
        //             }
        //         }
        //     }
        //     lower = upper;
        // }
        // for(auto i:dp){
        //     cout<<i<<" ";
        // }
        // return dp[dp.size() - 1];
    }
};