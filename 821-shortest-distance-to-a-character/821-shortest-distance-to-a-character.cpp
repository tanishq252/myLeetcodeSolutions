class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> v(s.length(), 0);
        int p1=0, p2=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int c1=0;
            int c2=0;
            if(s[i] == c){
                v[i] = 0;
            }
            else{
                if(i<n-1){
                    for(int j=i+1;j<n;j++){
                    c1++;
                    if(s[j]==c){
                        v[i] = c1;
                        break;
                    }
                    else{
                        v[i] = n;
                    }
                }
                for(int j=i-1;j>=0;j--){
                    c2++;
                    if(s[j]==c){
                        v[i] = min(v[i], c2);
                        break;
                    }
                }
                }else if(i==n-1){
                    for(int j=i-1;j>=0;j--){
                    c2++;
                    if(s[j]==c){
                        v[i] = c2;
                        break;
                    }
                }
                }
                
            }
        }
        return v;
    }
};