class Solution {
public:
    int tribonacci(int n) {
        vector<int> v = {0,1,1};
        for(int i=3;i<=n;i++){
            v.push_back(v[i-2]+v[i-1]+v[i-3]);
        }
        return v[n];
    }
};