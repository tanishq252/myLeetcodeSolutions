class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> v;
        int s = 0;
        if(arr.size()==1){
            return arr[0];
        }
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
        }
        if(arr.size()%2!=0){s = 2*s;}
        for(int i=3;i<arr.size();i+=2){
            for(int j = 0;j<=arr.size()-i;j++){
                for(int k = 0;k<i;k++){
                    s+=arr[j+k];
                }
            }
        }
        
        return s;
    }
};