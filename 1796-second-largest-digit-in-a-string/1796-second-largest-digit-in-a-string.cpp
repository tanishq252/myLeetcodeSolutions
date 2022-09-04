class Solution {
public:
    int secondHighest(string s) {
        priority_queue<int> pq;
        set<int> st;
        for(auto &i:s){
            if(i-'0' >= 0 and i-'0' < 10 and st.find(i-'0') == st.end()){
                pq.push(i-'0');
                st.insert(i-'0');
            }
        }
                if(pq.empty()) return -1;
        pq.pop();
        if(pq.empty()) return -1;
        return pq.top();
    }
};