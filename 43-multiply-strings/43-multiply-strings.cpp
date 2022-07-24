class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string ans(m+n, '0');        
        string tempAns(m+n, '0');

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int currentProduct = (num1[i]-'0')*(num2[j]-'0') + (ans[i+j+1]-'0');
                ans[i+j+1] = currentProduct%10 + '0';
                ans[i+j] += currentProduct/10;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0') return ans.substr(i);
        }
        return (ans == tempAns) ? "0":ans;
    }
};