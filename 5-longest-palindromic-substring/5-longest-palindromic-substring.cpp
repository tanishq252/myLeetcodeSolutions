class Solution {
public:
    string longestPalindrome(string s) {
        int m = 1;
        string ans = "";
        ans+=s[0];
        if(s.size() == 1) return s;
        for(int i=0;i<s.size();i++){
            int left = i, right=i;
            while(left>=0 and right<s.size() and s[left] == s[right]){
                left--;right++;
            }
            string s1(s.begin()+(left+1), s.begin()+right);
            if(s1.size() > m){
                ans = s1;
                m = ans.size();
            }
            left = i, right=i+1;
            while(left>=0 and right<s.size() and s[left] == s[right]){
                left--;right++;
            }
            string s2(s.begin()+left+1, s.begin()+right);
            if(s2.size() > m){
                ans = s2;
                m = ans.size();
            }
        }
        return ans;
    }
};