class Solution {
public:
    int myAtoi(string str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
        
//         int sign = 0;bool neg = false;
//         string ans = "";int i=0;
//         while(i<s.length()){
//             if(ans==""){
//                 if(s[i]=='+' or s[i]=='-'){
//                     if(s[i]=='-') {
//                         neg = true;
//                     }
//                     sign++;
//                     if(sign >= 2) return 0;
//                 }
//                 else if(s[i]-'0' >= 10 or s[i]-'0' < 0){
//                     // if(ans==""){
//                         break;
//                     // }
//                 }
//             }
//             else if(s[i]-'0' < 10 or s[i]-'0' >= 0){
//                 ans.push_back(s[i]);
//             }
//             i++;
//         }
//         int mx = INT_MAX;
//         i=0;long long int base = 0;
//         while(i<ans.length()){
//             int j = ans[i]-'0';
//             base = base*10 + j;

//             if(base >= mx){
//                 if(neg){
//                     return INT_MIN;
//                 }else{
//                     return INT_MAX;
//                 }
//             }
//             i++;
//         }
//         if(neg){
//             base*= -1;
//         }
//         cout<<ans;
//         return base;
    }
};