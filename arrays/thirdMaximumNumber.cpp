#include<bits/stdc++.h>
using namespace std;

int main(){

    // sol1
    // vector<int> nums = {1,2,3,4,4};
    // long long int m1,m2,m3;
    // m1=m2=m3 = LONG_LONG_MIN;
    // for (auto i:nums){
    //     if(i>m1){
    //         m3 = m2;
    //         m2 = m1;
    //         m1 = i;
    //     }
    //     else if(i>m2 && i<m1){
    //         m3 = m2;
    //         m2 = i;
    //     }
    //     else if(i>m3 && i<m2 && i<m1){
    //         m3 = i;
    //     }

    // }
    // if(m3 == LONG_LONG_MIN){return m1;}
    // return m3;
    // cout<<m1<<" "<<m2<<" "<<m3;


    vector<int> nums = {1,1,2,2};
    int c = 1;
    sort(nums.begin(), nums.end());
    for (int i=1;i<nums.size();i++){
        if (nums[i]!=nums[i+1])
            nums[c++] = nums[i];
    }
    int f = (nums.size()-c);
    while(f--){nums.pop_back();}
    if(nums.size()<=2){
        return nums[nums.size()-1];
    }
    else{
        return nums[nums.size()-3];
    }
    // for(int i=0;i<nums.size();i++){
    //     cout<<nums[i]<<" ";
    // }

    // vector<int> nums = {1,3,3,3,5,6,1,1,2,2,3,4,4};
    // vector<int> num;
    // int c = 1;
    // sort(nums.begin(), nums.end());
    // for (int i=0;i<nums.size()-1;i++){
    //     if(nums[i]!=nums[i+1]){num.push_back(nums[i]);}
    // }
    // num.push_back(nums[nums.size()-1]);
    // if(num.size() == 1){return num[0];}
    // else if(num.size() == 2){return num[1];}
    // else{return num[num.size()-3];}
}