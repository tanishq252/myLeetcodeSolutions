class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> st;
//         int n = pushed.size();
//         int j=0;
//         // if(pushed == popped){return true;}
//         for(int i=0;i<n;i++){
//             st.push(pushed[i]);
//             while(popped[j] == st.top() && !st.empty()){
//                 st.pop(); j++;
//             }
//         }
        
//         return st.empty();
        
        stack<int> s ;   // an empty stack
        int j = 0;
        for(int i= 0; i<pushed.size(); ++i)
        {
            s.push(pushed[i]);
            
			// check if pushed values is next to pe popped out.
            while(!s.empty() && s.top() == popped[j])
            {
                s.pop();
                ++j;
            }
        }
		// if stack is empty means sequence is correct.
        return s.empty();
    }
};