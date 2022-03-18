class Solution {
public:
    string smallestSubsequence(string str) {
        vector<int> maxIndex(26);
        vector<bool> isVisited(26, false);
        stack<int> st;
        int n = str.length();
        
        // we keep on traversing and find the max index of particular character present in string
        for(int i=0;i<n;i++){
            maxIndex[str[i]-'a'] = i;
        }
        
        //we have to keep on checking the presence of characters
        for(int i=0;i<n;i++){
            if(isVisited[str[i]-'a'] == false){
                //
                while(!st.empty()&&i<maxIndex[st.top()-'a']&&str[i]<st.top()){
                    isVisited[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(str[i]);
                isVisited[str[i]-'a'] = true;
            }
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};