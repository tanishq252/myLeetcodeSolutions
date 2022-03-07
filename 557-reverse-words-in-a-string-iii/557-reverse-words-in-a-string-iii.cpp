class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        for(int i=0;i<n/2;i++){
            swap(s[i], s[n-i-1]);
        }
        vector<string> v;
        string subStr="";
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                v.push_back(subStr);
                subStr = "";
                i++;
            }
            subStr+=s[i];
            if(i == n-1){
                v.push_back(subStr);
            }
        }
        reverse(v.begin(), v.end());
        string s1 = v[0];
        for(int i=1;i<v.size();i++){
            s1 = s1 + " " + v[i];
        }
        return s1;
    }
};