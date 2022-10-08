class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest=0, n=nums.size(), mn=INT_MAX, minVal=INT_MAX;
        if(n==3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            int l=i+1, r=n-1, s=nums[i];
            while(r>l){
                int sum = s+nums[r]+nums[l];
                if(sum==target) return sum;
                if(sum<target){
                    if(minVal>abs(target-sum)){
                        minVal = abs(target-sum);
                        mn = sum;
                    }
                    l++;
                }
                if(sum>target){
                    if(minVal>abs(target-sum)){
                        minVal = abs(target-sum);
                        mn = sum;
                    }
                    r--;
                }
            }
        }
        cout<<mn;
        return mn;
    }
};