// https://leetcode.com/problems/detect-capital/submissions/869412370/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int i=0,n=word.length();
        while(word[i]-'a' >= 0 and word[i]-'a'<26){
            i++;
        }
        if(i==n) return true;
        i=0;
        while(word[i]-'A' >= 0 and word[i]-'A'<26){
            i++;
        }
        if(i==n) return true;
        i=1;
        if(word[0]-'A' >= 0 and word[0]-'A'<26){
            while(word[i]-'a' >= 0 and word[i]-'a'<26){
                i++;
            }
            if(i==n) return true;
        }
        return false;
    }
};