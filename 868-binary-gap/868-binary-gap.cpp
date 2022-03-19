class Solution {
public:
    int toBin(int x){
        vector<int> v;int c=INT_MIN;int maxD = 0;
        while(x>0){
            // (x%2)?v.push_back(1):v.push_back(0);
            if(x%2==1){
                maxD = max(maxD, c);
                c=0;
            }
            c++;
            cout<<x%2<<" ";
            x/=2;
            
        }
        maxD = max(maxD, c);
        cout<<maxD;
        return maxD;
    }
    int binaryGap(int n) {
        if((bitset<32>(n)).count() == 1){return 0;}
        return toBin(n);
        // return 0;
    }
};