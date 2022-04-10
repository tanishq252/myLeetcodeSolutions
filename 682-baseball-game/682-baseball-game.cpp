class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        stack<int> st;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                st.pop();
                v.pop_back();}
            else if(ops[i]=="D"){
                st.push(st.top()*2);
                v.push_back(v[v.size()-1]*2);}
            else if(ops[i]=="+"){
                int prev = st.top();
                st.pop();
                int newScore = prev+st.top();
                st.push(prev);
                st.push(newScore);
                v.push_back(v[v.size()-1]+v[v.size()-2]);}
            else{
                st.push(stoi(ops[i]));
                v.push_back(stoi(ops[i]));}
        }
        int s = 0;
        int sum;
        while(!st.empty()){
            cout<<st.top()<<" ";
            s+=st.top();
            st.pop();
        }
        return s;
    }
};