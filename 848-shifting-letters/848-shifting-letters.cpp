class Solution {
public:
    
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        string alp = "abcdefghijklmnopqrstuvwxyz";
        vector<long long int> shift(n, 0);
        int mod = 1000000009;
        for(int i=0;i<n;i++){
            shift[i] = shifts[i];
        }
        for(int i=n-2;i>=0;i--){
            shift[i]+=(shift[i+1]);
        }
        for(int i=0;i<n;i++){
            long long int j = s[i]-'a';
            j+= shift[i];
            j%=26;
            s[i] = alp[j];
        }
        return s;
    }
};