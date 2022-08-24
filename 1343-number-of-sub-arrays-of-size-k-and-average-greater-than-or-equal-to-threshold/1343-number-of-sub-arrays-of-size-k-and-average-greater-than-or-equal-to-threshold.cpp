class Solution {
public:
    int numOfSubarrays(vector<int>& v, int k, int threshold) {
        int n = v.size();int c = 0;int ans = k*threshold;
        if(n<3) return 0;
        int sum = accumulate(v.begin(), v.begin()+k, 0);
        if(sum >= ans) c++;
        if(k == n){
            if(sum == accumulate(v.begin(), v.end(), 0)){
                return 1;
            }else{
                return 0;
            }
        }

        for(int i=k;i<n;i++){
            sum -= v[i-k];
            sum += v[i];
            if(sum>=ans) c++;
            
        }
        
        return c;
    }
};