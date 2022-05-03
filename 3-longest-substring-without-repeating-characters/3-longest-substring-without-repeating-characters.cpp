class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0, right = 0, ans = 0;
        map<char, int> m;
        while(right<s.size()){
            char r = s[right];
            m[r]++;
            while(m[r]>1){
                char l = s[left];
                left++;
                m[l]--;
            }
            right++;
            ans = max(ans, right-left);
        }
        return ans;
        
//      Passed 986/987 test cases    
        
//         int l = s.length();
//         if(l==0){return 0;}
//         int i=1;
//         cout<<l;
//         vector<int> v = {1};
//         for (int j=0;j<l;j++){
//             int i = j;
//             set<char> st;
//             st.insert(s[j]);
//             int ans = 1;
//             vector<char> vv;
//             while(i<l){
//                 if(st.find(s[i])==st.end()){
//                     st.insert(s[i]);
//                     i++;
//                     ans++;
//                 }
//                 else{
//                     if(ans == l-i){
//                         ans = 1;
//                         st.clear();
//                         st.insert(s[i]);
//                         i++;
//                         break;}
//                     ans = 1;
//                     st.clear();
//                     st.insert(s[i]);
//                     i++;
//                 }
//             }
//             v.push_back(ans);
//         }
    
//         return *max_element(v.begin(), v.end());
    }
};