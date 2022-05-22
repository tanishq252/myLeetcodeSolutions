class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<=s.size();i++){
            
            int left = i, right = i;
            
            while(left>=0 and right<s.size() and s[right]==s[left]){
                ans++; left--;right++;
            }
            
            left = i, right = i+1;
            
            while(left>=0 and right<s.size() and s[right]==s[left]){
                ans++; left--;right++;
            }
            
        }
        return ans;
    }
    
    
//     129/130 passed
    
//     bool isPal(string s){
//         string s1(s.begin(), s.end());
//         reverse(s1.begin(), s1.end());
//         return s==s1;
//     }
    
//     void traverse(string st, int s){
//         for(int i=0;i<st.size()-s+1;i++){
//             string st1(st.begin()+i, st.begin()+i+s);
//             if(isPal(st1)) ans++;
//         }
//     }
    
//     int countSubstrings(string s) {
//         cout<<isPal("aab");
//         for(int i=1;i<=s.size();i++){
//             traverse(s, i);
//         }
//         return ans;
//     }
};