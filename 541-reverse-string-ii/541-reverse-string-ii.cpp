class Solution {
public:
    string reverseStr(string s, int k) {
        char t;
        if(s.length() == 1){return s;}
        if(k>s.length()){
            reverse(s.begin(), s.end());
            return s;
        }
        for(int i=0;i<s.length();i+=(2*k)){
            if((i+k)<=s.length())
            {reverse(s.begin()+i, s.begin()+i+k);}
            else if(s.length()-i+1< k){
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }
};