#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {0};
    vector<int> arr;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0) arr.push_back(nums[i]);
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2!=0) arr.push_back(nums[i]);
    }
    for(int i=0;i<nums.size();i++){
        cout<<arr[i]<<" ";
    }
}