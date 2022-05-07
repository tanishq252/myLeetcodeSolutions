class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2){return false;}
        set<int> st(nums.begin(), nums.end());
        if(st.size()<3){return false;}
        vector<int> minValues(nums.size());
        int min = nums[0];
        minValues[0] = min;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min){
                minValues[i] = nums[i];
                min = nums[i];
            }else{
                minValues[i] = min;
            }
        }
        
        stack<int> s;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] > minValues[i]){
                while(!s.empty() && s.top()<=minValues[i]){
                    s.pop();
                }
                if(!s.empty() &&  s.top()<nums[i]){
                    return true;
                }
                s.push(nums[i]);
            }
        }
                return false;

        
        
//         99 test cases
        
        // vector<pair<int, int>> v;
        // set<int> s(nums.begin(), nums.end());
        // if(s.size()<3){return false;}
        // vector<int> n = nums;
        // nums = {};
        // nums.push_back(n[0]);
        // int m = 1;
        // for(int i=0;i<n.size()-1;i++){
        //     if(n[i+1]!=n[i]){
        //         nums.push_back(n[i+1]);
        //         cout<<n[i+1];
        //     }
        // }
        // for(int i=1;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[j] < nums[i]){
        //             v.push_back({i, nums[j]});
        //         }
        //     }
        // }
        // for(auto i:v){
        //     cout<<i.first<<" "<<i.second<<"\n";
        //     for(int j=0;j<i.first;j++){
        //         if(nums[j]<i.second){
        //             return true;
        //         }
        //     }
        // }
        
//         90 cases
        
        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         if(nums[i]<nums[j]){
        //             for(int k=j+1;k<nums.size();k++){
        //                 if(nums[k]>nums[i] && nums[k]<nums[j]){
        //                     return true;
        //                 }
        //             }
        //         }
        //     }
        // }
    }
};