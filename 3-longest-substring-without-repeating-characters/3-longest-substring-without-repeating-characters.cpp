class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                int n = s.length();
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }
        set<char> st;
        int ans = 1;
        string dummy = "";
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n){
                st.insert(s[j]);
                dummy += s[j];
                if(dummy.size() == st.size()){
                    j++;
                    continue;
                }else{
                    // cout<<max(st.size(), ans);
                    if(st.size()>ans){
                        ans = st.size();
                        cout<<ans;
                    }
                    // cout<<st.size()<<"\n";
                    st.clear();
                    dummy = "";
                    break;
                }
            }
        }
        return ans;
    }
};