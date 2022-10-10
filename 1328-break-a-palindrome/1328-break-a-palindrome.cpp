class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1) return "";
        set<char> st;
        for(auto &i:palindrome) st.insert(i);
        if(st.size() == 1){
            if(st.find('a') == st.end()){
                palindrome[0] = 'a';
                return palindrome;
            }else{
                palindrome[n-1] = 'b';
                return palindrome;
            }
        }
        bool changed = false;
        // while(!changed){
            int i=0;
            while(i<n/2){
                if(palindrome[i]=='a') i++;
                else{
                    palindrome[i]='a';
                    return palindrome;
                }
            }
        if(i==n/2){
            palindrome[n-1]='b';
        }
        // }
        return palindrome;
    }
};