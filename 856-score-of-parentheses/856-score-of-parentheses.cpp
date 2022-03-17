class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int currScore = st.top();
                st.pop();
                int prevScore = st.top();
                st.pop();
                st.push(prevScore + max(currScore*2, 1));
            }
        }
        int finalScore = st.top();
        return finalScore;
    }
};