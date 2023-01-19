//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int func(int A, int B, int C, int D){
        int moves=0;
        while(A>C){
            A/=2;
            moves++;
        }
        while(B>D){
            B/=2;moves++;
        }
        return moves;
    }
    int carpetBox(int A, int B, int C, int D){
        return min(func(A,B,C,D),func(B,A,C,D));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends