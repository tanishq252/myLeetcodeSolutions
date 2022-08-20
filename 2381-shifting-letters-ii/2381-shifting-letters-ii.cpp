class Solution {
public:
    //tle
    // string alp = "abcdefghijklmnopqrstuvwxyz";
    // void shift(string &s, vector<int> shif){
    //     if(shif[2] == 0){
    //         for(int i = shif[0];i<=shif[1];i++){
    //             int j = s[i] - 'a';
    //             j--;
    //             if(j == -1){
    //                 s[i] = alp[25];
    //             }else{
    //                 s[i] = alp[j];
    //             }
    //         }
    //     }else{
    //         for(int i = shif[0];i<=shif[1];i++){
    //             int j = s[i] - 'a';
    //             j++;
    //             if(j == 26){
    //                 s[i] = alp[0];
    //             }else{
    //                 s[i] = alp[j];
    //             }
    //         }
    //     }
    // }
    
    // string shiftingLetters(string s, vector<vector<int>>& shifts) {
    //     vector<long long int> v(s.length(), 0);string alp = "abcdefghijklmnopqrstuvwxyz";
    //     for(auto &i:shifts){
    //         if(i[2] == 0){
    //             for_each(v.begin()+i[0], v.begin()+i[1]+1, [](long long int& j) { j--; });
    //         }else{
    //             for_each(v.begin()+i[0], v.begin()+i[1]+1, [](long long int& j) { j++; });
    //         }
    //     }
    //     cout<<s.length();
    //     for(int j=0;j<s.length();j++){
    //         // cout<<v[j]<<" ";
    //         long long int k = s[j]-'a';
    //         k += v[j];
    //         // cout<<k<<"\n";
    //         if(k<0){
    //             k = abs(k);
    //             k%=26;
    //             s[j] = alp[26-k];
    //             if(s[j]=='\x00'){
    //                 s[j]='a';
    //             }
    //         }
    //         else if(k>25){
    //             s[j] = alp[k%26];
    //         }
    //         else{
    //             s[j] = alp[k];
    //         }
    //     }
    //     return s;
    // }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        string alp = "abcdefghijklmnopqrstuvwxyz";
        vector<int> v(n+1, 0);
        for(auto &i:shifts){
            int l = i[0],r = i[1], dir=i[2];
            if(dir == 0){
                v[l]--;
                v[r+1]++;
            }else{
                v[l]++;
                v[r+1]--;
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            int j = s[i]-'a'+26+(sum%26);
            j%=26;
            cout<<j<<" ";
            s[i] = alp[j];
        }
        return s;
    }
};