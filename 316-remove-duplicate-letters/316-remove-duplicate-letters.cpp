class Solution {
public:
    string removeDuplicateLetters(string str) {
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
            if(!isVisited[str[i]-'a']){
                //if stack is not empty and top element of stack is repeated once again
                //in the string which means that the top most element has it's duplicate
                //and the current character is appearing before the top charcter in alphabetical 
                //sequence then we can keep on popping element from stack
                //else we have to push current string and make it visited so 
                //that we can skip duplicate characters
                while(!st.empty()&&i<maxIndex[st.top()-'a']&&str[i]<st.top()){
                    isVisited[st.top()-'a'] = false;
                    st.pop();
                }
                st.push(str[i]);
                isVisited[str[i]-'a'] = true;
            }
        }
        
        string ans;
        // while stack goes empty keep on concatenating the string
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};