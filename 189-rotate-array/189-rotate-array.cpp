class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int j;
        vector<int> v;
        if(k%n == 0){return;}
        else{j = k%n;}
        for(int i= 0;i<j;i++){
            v.push_back(nums[i+n-j]);
        }
        for(int i= 0;i<n-j;i++){
            v.push_back(nums[i]);
        }
        for(int i= 0;i<n;i++){
            nums[i] = v[i];
        }
        
//         ///////////////////////////
//         Passed 37/38 cases with TLE
        // int j;
        // if(k%n == 0){return;}
        // else{j = k%n;}
        // for(int i= 0;i<1;i++){
        //     int t= nums[n-1];
        //     nums.pop_back();
        //     nums.insert(nums.begin(), t);
        // }
        // cout<<j<<" "<<n;
        
//         ///////////////////////////
//         Passed 34/38 cases with TLE
//         int t;
//         for(int j = 0;j<k;j++){
//             int i=n-1;
//             t = nums[n-1];
//             while(i>0){
//                 nums[i] = nums[i-1];i--;
//             }
//             nums[0] = t;
//         }
    }
};