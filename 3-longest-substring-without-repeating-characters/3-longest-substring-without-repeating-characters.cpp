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
        int ans =0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n){
                if(st.find(s[j])==st.end()){
                    st.insert(s[j]);
                    ans++;
                    j++;
                }
                else{
                    pq.push(ans);
                    ans = 0;
                    st.clear();
                    break;
                }
            }
        }
        
        return pq.top();
    }
};