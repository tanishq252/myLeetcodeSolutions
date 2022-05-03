class Solution {
public:
    int minimumLength(string s) {
        deque<char> dq;
        for(int i=0;i<s.length();i++){
            dq.push_back(s[i]);
        }
        if(s.length()==1){return 1;}
        while(dq.size()>0){
            char a = dq.front();
            if(dq.front() == dq.back()){
                while(dq.front()==a && dq.size()!=0){
                dq.pop_front();
                }
                while(dq.back()==a && dq.size()!=0){
                    dq.pop_back();
                }
                if(dq.size()==1){
                    return 1;
                }
            }
            if(dq.front()!=dq.back() && dq.size()!=0){
                break;
            }
            
        }
        
        cout<<dq.size();
        return dq.size();
        
        
    }
};