class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==1) return true;
        int x=1;
        vector<vector<int>> freq;
        while(x<=pow(2, 29)){
            x*=2;
            // if(x>n) break;
            vector<int> v(10, 0);
            for(auto i:to_string(x)){
                v[i-'0']++;
            }
            freq.push_back(v);
        }
        vector<int> vc(10, 0);
        for(auto i:to_string(n)){
            vc[i-'0']++;
        }
        for(auto i:freq){
            if(i == vc){
                return true;
            }
        }
        return false;
    }
};