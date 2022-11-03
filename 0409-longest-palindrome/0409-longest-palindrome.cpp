class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(auto &i:s){
            mp[i]++;
        }
        int ans=0, mx = INT_MIN, flag=0;
        for(auto &i:mp){
            if(i.second%2==1){
                mx = max(mx, i.second);
            }
        }
        
        for(auto &i:mp){
            if(i.second==mx){
                if(flag == 0){
                    flag = 1;
                    ans+=mx;
                }else{
                    ans+=(mx-1);
                }
            }else{
                if(i.second%2==1){
                    ans+=(i.second-1);
                }else{
                    ans+=i.second;
                }
            }
        }
        
        return ans;
    }
};