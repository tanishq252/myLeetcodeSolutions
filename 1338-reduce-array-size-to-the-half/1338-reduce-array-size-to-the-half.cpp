class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int m = *max_element(arr.begin(), arr.end());
        vector<int> mp(m+1, 0);
        set<int> st;
        int n = arr.size();
        for(auto i: arr){
            mp[i]++;
        }
        sort(mp.begin(), mp.end(), [](int a, int b){
            return a>b;
        });
        int sum = 0, size =0 ;
        for(auto i:mp){
            sum+=i;
            size++;
            if(sum >= (n%2 + n/2)){
                return size;
            }
        }
        return 0;
    }
};