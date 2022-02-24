#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1};
    vector<int> disappeared(nums.size());
    vector<int> answer;
    for (int i=0;i<nums.size();i++){
        disappeared[nums[i]-1]++;
    }
    for (int i=0;i<nums.size();i++){
        if(disappeared[i] == 0) answer.push_back(i+1);
    }
    for (int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}