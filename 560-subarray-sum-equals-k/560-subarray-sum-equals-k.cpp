class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long int, int> mp;
        int n = nums.size();int ans = 0;
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i] == k) ans++;
            if(mp.find(nums[i]-k)!=mp.end()){
                ans+=mp[nums[i]-k];
            }
            mp[nums[i]]++;
            
        }
        // for(int i=0;i<n;i++){
        //     int s = 0;
        //     for(int j=i;j<n;j++){
        //         s+=nums[j];
        //         mp[s]++;
        //     }
        // }
        return ans;
    }
};