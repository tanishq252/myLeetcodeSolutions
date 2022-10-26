class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return false;
                if(k==1) return true;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        map<int, int> mp;
        int i=0;
        while(i<n){
            if(i>0){
                if(nums[i]%k==0) return true;
                if(nums[i]%k == nums[i-1]%k){
                    int j=i, c=0;
                    while(nums[j]%k==nums[j-1]%k and j<n){
                        j++;c++;
                        if(j==n) break;
                    }
                    
                    if(c>1){
                        return true;
                    }
                    else if (j==n) {
                        if(mp[nums[i]%k] > 1){
                            return true;
                        }
                        return false;
                    }
                    else{
                        // if(mp[nums[i]%k] == 1){
                        //     return true;
                        // }else{
                        //     mp[nums[i]%k]++;
                        // }
                        i++;
                    }
                    i++;
                }else{
                    cout<<i<<"\n";
                    if(mp[nums[i]%k] == 1){
                        return true;
                    }else{
                        mp[nums[i]%k]++;
                    }
                    i++;
                }
            }else{
                mp[nums[i]%k]++;
                i++;
            }
        }
        return false;
    }
};