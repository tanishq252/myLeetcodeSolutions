class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string ans(n+m, '0');        
        string tempans(n+m, '0');
        // int product;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int product= (num1[i]-'0')*(num2[j]-'0')+(ans[i+j+1]-'0');
                ans[i+j+1] = product%10 + '0';
                cout<<product<<" ";
                ans[i+j] += product/10;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0') return ans.substr(i);
        }
        return (tempans == ans)? "0":ans ;
    }
};