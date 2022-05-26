class Solution {
public:
    string ans="1";
    
    void execute(string s){
        int i=0;
        string temp="";
        while(i<s.length()){
            int c=1;
            while(s[i] == s[i+1] and i<s.length()-1){
                i++;c++;
            }
            temp += (to_string(c)+s[i]);
            i++;
        }
        ans = temp;
    }
        
    string countAndSay(int n) {
        
        if(n==1) return ans;
        for(int i=1;i<n;i++){
            execute(ans);
        }
        return ans;
    }
};