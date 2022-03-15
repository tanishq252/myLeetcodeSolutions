class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    s[i] = '0';
                }else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            s[st.top()] = '0';
            st.pop();
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};