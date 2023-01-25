//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool matchPrefix(string s, string pre){
        if(pre.length()>s.length()) return false;
        for(int i=0;i<pre.length();i++){
            if(s[i]!=pre[i]) return false;
        }
        return true;
    }
    int minOperation(string s) {
        // code here
        if(s.length() == 1) return 1;
        string ss="",t="", s1="";
        int c=0,i=0;
        int mx=0;

        while(i<s.length()){
            ss+=s[i++];
            if(matchPrefix(s,ss+ss)){
                if(ss.length()>mx) mx = ss.length();
            }
        }
        return (mx==0) ? s.length() : s.length()-mx+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends