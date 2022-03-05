#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        // int i= 0;
        // int j =nums.size()-1 ;
        // map<int, int> m;
        // for(int k = 0;k<nums.size();k++){
        //     m[nums[k]] = k;
        // }
        // sort(nums.begin(), nums.end());
        // while(i<j){
        //     if(nums[i]+nums[j] == target && i!=j){
        //         v.push_back(m[nums[i]]);
        //         v.push_back(m[nums[j]]);
        //         return v;
        //     }
        //     else if(nums[i]+nums[j] > target){
        //         j--;
        //     }
        //     else if(nums[i]+nums[j] < target){
        //         i++;
        //     }
        // }
        
        
//         passed test cases but wasn't solved with 2 pointers method
        for(int i=0;i<nums.size();i++){
            for (int j=0;j<nums.size();j++){
                if(nums[i]+nums[j]== target && (i!=j)){
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return v;

    }
};

