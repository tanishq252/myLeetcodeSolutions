class Solution {
public:
    bool isSD(int n){
        int x = n;
        if(n%10 == 0){return false;}
        if(n<10){return true;}
        while(n>0){
            int j = n%10;
            if(j==0){return false;}
            if(x%j!=0){return false;}
            n/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++){
            if(isSD(i)){v.push_back(i);}
        }
        return v;
    }
};