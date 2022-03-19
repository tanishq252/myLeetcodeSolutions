class Solution {
public: 
    vector<long long int> mySqrtVect(int x) {
        long long int j = 0;
        vector<long long int> v;
        while(j*j<=x){
            v.push_back(j*j);
            j++;
            }
        return v;
        }
    bool judgeSquareSum(int c) {
        vector<long long int> v = mySqrtVect(c);
        int i=0; 
        int j = v.size()-1;
        while(i!=j){
            if(v[i]+v[j]<c){i++;}
            else if(v[i]+v[j]>c){j--;}
            else if(v[i]+v[j] == c){return true;}
        }
        if(v[i]+v[j] == c){return true;}
        return false;
        
    }
};