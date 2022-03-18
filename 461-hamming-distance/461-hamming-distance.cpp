class Solution {
public:
    vector<int> tobinary(int n){
        vector<int> v;
        while(n>0){
            v.push_back(n%2);
            n/=2;
        }
        reverse(v.begin(), v.end());
        return v;
    }
    
    int hammingDistance(int x, int y) {
        vector<int> v1, v2;
        v1 = tobinary(x);        
        v2 = tobinary(y);
        if(v1.size()>v2.size()){
            reverse(v2.begin(), v2.end());
            cout<<v1.size()-v2.size();
            while(v1.size()!=v2.size()){
                v2.push_back(0);
            }
            reverse(v2.begin(), v2.end());
        }
        else if(v1.size()<v2.size()){
            reverse(v1.begin(), v1.end());
            while(v1.size()!=v2.size()){
                v1.push_back(0);
            }
            reverse(v1.begin(), v1.end());
        }
        int c=0;
        for(int i=0;i<v1.size();i++){
            c+= (v1[i] != v2[i])?1:0;
        }
    return c;
    }
};