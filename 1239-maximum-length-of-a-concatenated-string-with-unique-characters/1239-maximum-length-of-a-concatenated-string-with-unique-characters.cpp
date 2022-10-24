class Solution {
public:
    int mxSeq = INT_MIN;        
    vector<int> v;


    void backtrack(vector<string> &arr, int i, string &s){
        v = vector<int>(26, 0);
        for(int j=0;j<s.length();j++){
            if(v[s[j]-'a']==1){
                return;
            }
            v[s[j]-'a']++;
        }
        mxSeq = mxSeq > s.length() ?mxSeq : s.length();
                if(i==arr.size()) return;

        string ss = s+arr[i];
        backtrack(arr, i+1, ss);
        backtrack(arr, i+1, s);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        mxSeq = 0;
        if(arr.size()==1){
            set<char> st(arr[0].begin(), arr[0].end());
            return st.size()==arr[0].length() ? arr[0].length():0;
        }
        v = vector<int>(26, 0);
        string s="";
        backtrack(arr, 0, s);
        cout<<mxSeq;
        return mxSeq;
    }
};