class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        if(a[0]<a[n-1]){
            return a[0];
        }else if(a[0]>a[n-1]){
            int i=n-1;
            while(a[i-1]<a[i] and i>=1){
                i--;
            }
            return a[i];
        }
        return a[0];
    }
};