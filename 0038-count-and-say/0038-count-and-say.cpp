class Solution {
public:
    string countAndSay(int n) {
        string s="11",ss;
        if(n==1) return "1";
        if(n==2) return "11";
        int i=2;
        while(i<n){
            ss="";
            int c=1,j=1;
            while(j<s.length()){
                if(s[j]==s[j-1]){
                    c++;
                }
                else{
                    ss+=(to_string(c)+s[j-1]);
                    c=1;
                }
                j++;
            }
            ss+=(to_string(c)+s[j-1]);
            s = ss;i++;
            cout<<s<<"\n";
        }
        return s;
    }
};