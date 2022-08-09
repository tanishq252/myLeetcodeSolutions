class Solution {
public:
    int mod = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<int> dp(arr.size()-1, 0);
        map<int, long long> mp;
        sort(arr.begin(), arr.end());
        for(auto i:arr){
            mp[i]=1;
        }
        for(int i=0;i<arr.size();i++){
            for(int j=2;j<sqrt(arr[i]);j++){
                if(arr[i]%j == 0 and (j * (arr[i]/j) == arr[i])){
                    if(mp.find(j)!=mp.end() and mp.find(arr[i]/j)!=mp.end()){
                        mp[arr[i]]+= (((((mp[j]%mod)*(mp[arr[i]/j]%mod))%mod)*2)%mod);
                    }
                }
            }
            if(int(sqrt(arr[i]))*int(sqrt(arr[i])) == arr[i] and mp.find(sqrt(arr[i]))!=mp.end()){
                mp[arr[i]]+= (((mp[sqrt(arr[i])]%mod)*(mp[sqrt(arr[i])])%mod)%mod);
            }
            
        }
        
        // 
        long s = 0;
        for(auto i:mp){
            s+= (i.second);
        }
        
        return s%mod;
    }
};