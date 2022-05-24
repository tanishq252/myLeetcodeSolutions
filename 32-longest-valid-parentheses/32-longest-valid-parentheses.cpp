class Solution {
public:
    int maxLen=0;
    int longestValidParentheses(string s) {
        int left=0, right=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                left++;
            }else if(s[i]==')'){
                right++;
            }
            
            if(left==right){
                maxLen = max(maxLen, left+right);
            }else if(right>=left){
                left = right = 0;
            }
        }
        
        left=0, right=0;
        for(int i=s.length();i>=0;i--){
            if(s[i] == '('){
                left++;
            }else if(s[i]==')'){
                right++;
            }
            
            if(left==right){
                maxLen = max(maxLen, left+right);
            }else if(right<=left){
                left = right = 0;
            }
        }
        return maxLen;
    }
};