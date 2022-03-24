class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(), arr.end());
        int c=0;
        int i = 0; int j = arr.size()-1;
        while(i<=j){
            c++;
            if(arr[i]+arr[j]<=limit)i++;
            j--;
        }
        return c;
    }
};