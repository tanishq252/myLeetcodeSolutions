class Solution {
public:
    
    bool ispalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int flag = 0;
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(ispalindrome(s, i, j-1)){
                    if(flag==1){
                        return false;
                    }
                    flag+=1;
                    j--;
                }
                else if(ispalindrome(s, i+1, j)){
                    if(flag==1){
                        return false;
                    }
                    flag+=1;
                    i++;
                }
                else {return false;}
            }
            i++;j--;
        }
        return true;
        
    }
};