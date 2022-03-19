class Solution {
public:
    vector<string> buildArray(vector<int>& target, int nn) {
        stack<int> st;
        vector<string> v;
        st.push(1);
        v.push_back("Push");
        int n=2;
        int i=0;
        while(i<target.size()){
            if(target[i] == st.top()){
                st.push(n++);
                i++;
                v.push_back("Push");
            }else if(target[i]>st.top()){
                while(target[i]>st.top()){
                    st.pop();
                    st.push(n++);
                    v.push_back("Pop");
                    v.push_back("Push");
                }
                if(target[i] == st.top()){
                    st.push(n++);
                    i++;
                    v.push_back("Push");
                }
            }
        }
        if(n-target[i-1]>1){v.pop_back();}
        return v;
    }
};