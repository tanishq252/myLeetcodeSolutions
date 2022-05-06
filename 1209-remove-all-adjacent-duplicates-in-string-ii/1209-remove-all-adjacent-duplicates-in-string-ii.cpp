class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s;
        
        stack<pair<char,int>> stk;
        for(int i=0; i<n; ++i){
            if(stk.empty() || stk.top().first != s[i]) stk.push({s[i],1});
            else{
                auto prev = stk.top();
                stk.pop();
                stk.push({s[i], prev.second+1});
            }
            if(stk.top().second==k) stk.pop();
        }
        
        string ans = "";
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
//         passed 17/20 cases
        
//         if(s.length() == 1){
//             return s;
//         }
//         unordered_map<char, int> m;
//         stack<char> st;
        
// //         m[s[0]]++;
// //         st.push(s[0]);
//         int streak = 1;
        
//         for(int i=0;i<s.length();i++){
//            if(st.empty()){
//                 m[s[i]] = 1;
//                 st.push(s[i]);
//             }
//             else if(s[i]!=st.top()){
//                 m[s[i]] += 1;
//                 st.push(s[i]);
//                 streak = 1;
//             }
//             else if(s[i] == st.top()){
//                 m[s[i]]++;
//                 st.push(s[i]);
//                 streak++;
//             }
            
//             if(m[s[i]]>=k && st.top()==s[i]){
//                 int j = k;
//                 while(j && !st.empty()){
//                     if(s[i]==st.top()){
//                         st.pop();
//                         m[s[i]]--;
//                         }
//                     j--;
//                 }
//             }
//         }
        
//         vector<char> ans;
        
//         while(!st.empty()){
//             char c=st.top();
//             st.pop();
//             ans.push_back(c);
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         string anss;
        
//         for(auto i:ans){
//             cout<<i<<" ";
//             anss+=i;
//         }
//         return anss;
        
    }
};