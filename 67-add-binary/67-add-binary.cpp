class Solution {
public:
    string addBinary(string a, string b) {
        int n = (a.size()>=b.size())?(a.size()):(b.size());
        string p = "";
        if(b.size()>a.size()){
            for(int i=0;i<b.size()-a.size();i++){
                p += '0';
            }
            a = p+a;
        }else{
            for(int i=0;i<a.size()-b.size();i++){
                p += '0';
            }
            b = p+b;
        }
        string s="";
        char carry = '0';
        for(int i=n-1;i>=0;i--){
            if(a[i] == '0' && b[i] == '0'){
                if(carry == '0'){
                    s.push_back('0');
                }
                else{
                    s.push_back('1');carry = '0';
                }
            }
            else if(a[i] == '1' && b[i] == '1'){
                if(carry == '0'){
                    s.push_back('0'); carry = '1';
                }
                else{
                    s.push_back('1');carry = '1';
                }
            }
            else if((a[i] == '0' && b[i] == '1')|| (a[i] == '1' && b[i] == '0')){
                if(carry == '0'){
                    s.push_back('1');
                }
                else{
                    s.push_back('0');carry = '1';
                }
            }
        }
        if(carry == '1'){s.push_back('1');}
        reverse(s.begin(), s.end());
        return s;
    }
};