#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[c++] = nums[i];
            }
        }
        return c;
    }
};

// always try two pointers method for such questions