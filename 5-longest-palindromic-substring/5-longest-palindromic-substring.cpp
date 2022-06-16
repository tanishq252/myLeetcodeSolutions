class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        string ans = "";
        ans+=s[0];
        int n = s.length();
        for(int i=0;i<n-1;i++){
            left = i, right = i;
            while(left>=0 and right<=n-1 and s[left] == s[right]){
                left--;right++;
            }
            string ts1(s.begin()+left+1, s.begin()+right);
            if(ts1.length()>ans.length()){
                ans = ts1;
            }
            left = i, right = i+1;
            while(left>=0 and right<=n-1 and s[left] == s[right]){
                left--;right++;
            }
            string ts2(s.begin()+left+1, s.begin()+right);
            if(ts2.length()>ans.length()){
                ans = ts2;
            }
        }
        return ans;
    }
};