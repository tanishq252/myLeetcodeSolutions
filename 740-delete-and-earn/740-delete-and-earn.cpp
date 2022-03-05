class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
//         if size is 1 then it isn't required to move for further calculations
        if(n == 1){
            return nums[0];
        }
        
        int total = 10001;
        
//         defining a map with maximum size for updating freqencies properly
        vector<int> m(10001,0);
        for(int i = 0;i<n;i++){
            m[nums[i]]+=nums[i];
        }
        
//         taking two variables and we will return max of them
        int first = m[0];
        int second = max(first, m[1]);
        
//         now as we have the first two elements we are supposed
//         to keep on adding the first with current element and compare 
//         with second and assign maximum value as second 
//         and assign first value as old second
//         this will make sure that we have pair of maximum values
//         at end we have to return max of this pair
        
        for(int i=2;i<total;i++){
            int curr = max(second, first+m[i]);
            first = second;
            second = curr;
        }
        
        return max(second, first);
        
    }
};