class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i = s.length();
        int j = 0;
        int itr=0;
        vector<int> v;
        while(itr<=s.length()){
            if(s[itr] == 'I'){v.push_back(j++);itr++;}
            else{v.push_back(i--);itr++;}
        }
        return v;
    }
};