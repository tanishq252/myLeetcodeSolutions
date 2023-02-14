class Solution {
public:
    pair<char, char> calc(char a, char b, char c){
        if(c == '1'){
            if(a=='1' and b=='1') return {'1', '1'};            
            if(a=='0' and b=='0') return {'0', '1'};
            else return {'1', '0'};
        }else{
            if(a=='1' and b=='1') return {'1', '0'};            
            if(a=='0' and b=='0') return {'0', '0'};
            else return {'0', '1'};
        }
    }
    string addBinary(string a, string b) {
        int ab = abs((int)a.length()-(int)b.length());
        if(a.length() > b.length()){
            for(int i=0;i<ab;i++){
                b='0'+b;
            }
        }else{
            for(int i=0;i<ab;i++){
                a='0'+a;
            }
        }
        char ans, c='0';
        string s;
        for(int i=a.length()-1;i>=0;i--){
            pair<char, char> p = calc(a[i], b[i], c);
            s = p.second+s;
            c=p.first;
        }
        
        return (c=='1') ? c+s:s;
    }
};