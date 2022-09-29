class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> vec;
        int n=arr.size();
        if(n==k) return arr;
        for(auto &i:arr){
            vec.push_back(abs(i-x));
        }
        int s=accumulate(vec.begin(), vec.begin()+k, 0);
        int ms=s, mi=0;
        for(int i=1;i<=(n-k);i++){
            s-=vec[i-1];
            s+=vec[i+k-1];
            if(s<ms){
                ms = s; mi = i;
            }
        }
        return vector<int>(arr.begin()+mi, arr.begin()+mi+k);
    }
};