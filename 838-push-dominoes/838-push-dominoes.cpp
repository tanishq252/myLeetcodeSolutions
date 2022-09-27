class Solution {
public:
    string pushDominoes(string d) {
                d = 'L' + d + 'R';
        string res = "";
        for (int i = 0, j = 1; j < d.length(); ++j) {
            if (d[j] == '.') continue;
            int middle = j - i - 1;
            if (i > 0)
                res += d[i];
            if (d[i] == d[j])
                res += string(middle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                res += string(middle, '.');
            else
                res += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
            i = j;
        }
        return res;

//         int n = dominoes.length();
//         if(n==1) return dominoes;
//         // if(dominoes[0]=='R') 
//         // {
//         //     if(dominoes[1] == '.') dominoes[1] = 'R';
//         // }
//         for(int i=0;i<n;i++){
//             if(dominoes.substr(i, 3) == "R.L"){
//                 i+=3;
//                 if(i >= n-1) break;
//             }else if(dominoes.substr(i, 2) == "RL"){
//                 i+=2;
//             }
//             else if(dominoes[i]=='R' and i<n-1) 
//             {
//                 if(i==n-2) dominoes[n-1] = 'R';
//                 else if(dominoes[i+1]=='R') continue;
//                 else{
//                     int j=i+1, len=0, k, mid;
//                     while(j<n and dominoes[j]=='.'){
//                         j++;len++;
//                         if(dominoes[j]=='L' or dominoes[j] == 'R') break;
//                     }
//                     // cout<<"Len"<<len;
//                     if(dominoes[j] == 'L'){
//                         if(len%2==0){
                        
//                         mid = len/2+i;
//                             for(int k = i+1;k<mid+1;k++){
//                                 dominoes[k] = 'R';
//                             }
//                             for(int k=mid+1;k<j;k++){
//                                 dominoes[k] = 'L';
//                             }
//                         }else{
//                             mid = len/2 + 1 + i;
//                             for(int k = i+1;k<mid;k++){
//                                 dominoes[k] = 'R';
//                             }
//                             for(int k=mid+1;k<j;k++){
//                                 dominoes[k] = 'L';
//                             }
//                         }
                        
//                     }
//                     else if(dominoes[j] == 'R'){
//                         for(int k=i+1;k<j;k++) dominoes[k] = 'R';
//                     }
//                     else if(j==n){
//                         for(int k=i+1;k<n;k++){
//                             dominoes[k] = 'R';
//                         }
//                     }
//                     i = j;
//                 }
//             }else if(dominoes[i]=='L' and i>0){
//                 int j = i-1;
//                 while(dominoes[j]=='.' and j>0){
//                     dominoes[j] = 'L';
//                     j--;
//                 }
//                 dominoes[j]='L';
//             }
//             cout<<i<<" "<<dominoes<<"\n";
//         }
//         // string s = "RL";
//         // string t = s.substr(0,3);
//         cout<<dominoes;
//         return dominoes;
    }
};