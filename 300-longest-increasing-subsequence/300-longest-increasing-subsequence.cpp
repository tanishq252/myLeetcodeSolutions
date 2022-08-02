class Solution {
public:
//     int LIS(vector<int> &nums){
        
//     }
    
    int lengthOfLIS(vector<int>& nums){
        vector<int> lis(nums.size(), 1);
        for(int i=0; i<nums.size();i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] and lis[i] < lis[j]+1){
                    lis[i] = lis[j]+1;
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
    
//     priority_queue<int> pq;
    
//     void comboHelper(vector<int> &nums, vector<int> &combo, int index){
//         if(index == nums.size()) return;
//         if(combo.size()==0){
//             combo.push_back(nums[index]);
//             comboHelper(nums, combo, index+1);
//             combo.pop_back();
//             comboHelper(nums, combo, index+1);
//         }else{
//             if(combo[combo.size()-1] < nums[index]){
//                 for(auto i:combo){
//                     cout<<i<<" ";
//                 }
//                 cout<<nums[index]<<"\n";
//                 pq.push(combo.size()+1);
//                 combo.push_back(nums[index]);
//                 comboHelper(nums, combo, index+1);
//                 combo.pop_back();
//                 comboHelper(nums, combo, index+1);
//             }else{
//                 // combo.pop_back();
//                 // comboHelper(nums, combo, index+1);
//                 while(combo[combo.size()-1] >= nums[index]){
                    
//                     index++;
//                     if( index==nums.size()){
//                         return;
//                     }
//                 }
//                 if(index == nums.size()) return;
//                 for(auto i:combo){
//                     cout<<i<<" ";
//                 }
//                 cout<<nums[index]<<"\n";
//                 pq.push(combo.size()+1);
//                 combo.push_back(nums[index]);
//                 comboHelper(nums, combo, index+1);
//                 combo.pop_back();
//                 comboHelper(nums, combo, index+1);
//             }
            
//         }

//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> combo;
//         if(nums.size()==1) return 1;
//         pq.push(1);
//         int i=0;
//         while(nums[i+1]>nums[i]){
//             i++;
//             if(i==nums.size()-1){
//                 return i+1;
//             }
//         }
//         comboHelper(nums, combo, 0);
//         return pq.top();
//     }
};