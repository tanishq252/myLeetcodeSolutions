//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char> v1, v2;
        for(auto &i:str){
            if(i-'a'>=0){
                v1.push_back(i);
            }else{
                v2.push_back(i);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int c1=0, c2=0;
        string ans="";
        for(auto &i:str){
            if(i-'a'>=0){
                ans+=v1[c1++];
            }else{
                ans+=v2[c2++];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends