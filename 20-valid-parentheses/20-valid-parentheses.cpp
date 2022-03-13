class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length() == 1){return false;}
        if(s[0] == '}'||s[0] == ']'||s[0] == ')'){return false;}
        for(int i=0;i<s.length();i++){
            if(s[i] == '('||s[i] == '['||s[i] == '{'){
                st.push(s[i]);
            }
            else if(st.empty() && (s[i] == '}'||s[i] == ']'||s[i]== ')')){
                return false;
            }
            else{
                char top = st.top();
                if((s[i] == ')'&&top == '(')||(s[i] == ']'&&top == '[')||(s[i] == '}'&&top == '{')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){return true;}
        return false;
    }
};