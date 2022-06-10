class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        set<int> st;
        map<int, int> m;
        int r = 0, l= 0, sum = 0, ans = 0;
        while(r<n){
            m[nums[r]]++;
            sum+=nums[r];
            while(m[nums[r]]>1){
                m[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            r++;
            ans = max(ans, sum);
        }
        // int ans = 1;
        // int sum = 0, count =0;
        
        // for(int i=0;i<n;i++){
        //     int j = i;
        //     while(j<n){
        //         sum+=nums[j];
        //         count++;
        //         st.insert(nums[j]);
        //         if(count == st.size()){
        //             j++;continue;
        //         }else{
        //             if(sum-nums[j]>ans){
        //                 ans = sum - nums[j];
        //             }
        //             sum=0;
        //             count=0;
        //             st.clear();
        //             break;
        //         }
        //     }
        // }
        return ans;
    }
};