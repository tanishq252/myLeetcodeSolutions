class Solution {
public:
    vector<int> toBinary(int n){
        vector<int> v;
        while(n>0){
            n%2==0 ? v.push_back(1):v.push_back(0);
            n/=2;
        }
        return v;
    };
    
    int binToNum(vector<int> &a){
        int n=1;
        int c=0;
        int i=0;
        while(i<a.size()){
            c+= a[i]*n;
            i++;
            n*=2;
        }
        return c;
    }
    
    int findComplement(int num) {
        vector<int> v = toBinary(num);
        int j=v.size()-1;
        while(j>0){
            if(v[j] == 0){v.pop_back(); j--;}
            else if(v[j] == 1){break;}
        }
        return binToNum(v);
    }
};