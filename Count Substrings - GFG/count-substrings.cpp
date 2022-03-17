// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int countSubstr (string s)
	{
	    // your code here
	    int i=0;
	    int j = s.length();
    int c=0;
    while(i<s.length()){
        if(s[i] == '1'){c++;}
        i++;
    }
    // for(int i=0;i<s.length();i++){
    //     for(int j=i+1;j<s.length();j++){
    //         if(s[i] == '1' && s[j] == '1'){c++;}
    //     }
    // }
    // return c;
    // while(i<s.length())
    // {
    //     if(s[i] == '1'){
    //         int j = i+1;
    //         while(j<s.length()){
    //             if(s[j] == '1'){
    //                 c++;
    //             }
    //             j++;
    //         }
    //     }
    //     i++;
    // }
    return c*(c-1)/2;
	}
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        
        cout << ob.countSubstr (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends