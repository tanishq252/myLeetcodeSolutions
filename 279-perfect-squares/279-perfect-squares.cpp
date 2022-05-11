class Solution {
public:

    unordered_map<int, int> memoMap;
    int recurFunc(vector<int> &v, int target){
        if(target==0) return 0;
        if(memoMap[target]>0) return memoMap[target];
        int currentMin = INT_MAX;
        
        for(auto i:v){
            if(i>target) continue;
            currentMin = min(currentMin, 1+recurFunc(v, target-i));
        }
        return memoMap[target] = currentMin;
    }
    
    int numSquares(int n) {
        int i=1;
        vector<int> v;
        while((i*i)<n){
            v.push_back(i*i);
            i++;
        }
        if(i*i == n){
            return 1;
        }
        return recurFunc(v, n);
        
    }
};