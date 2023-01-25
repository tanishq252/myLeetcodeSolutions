//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()) st.push(s[i]);
            else{
                if(s[i]==st.top()){
                    while(s[i]==st.top()){
                        st.pop();
                        if(st.empty()) break;
                    }
                }
                else st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return (ans == "" )?"-1":ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends