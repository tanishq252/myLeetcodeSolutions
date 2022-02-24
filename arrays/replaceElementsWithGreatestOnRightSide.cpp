#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {17,3,4,9,2,3,8};
    int pervMax = arr[0];
    if(arr.size() == 1){
        // return;
        arr[0] = -1;
    }
    for(int i=0;i<arr.size();i++){
        pervMax = arr[i+1];
        for(int j=i+1;j<arr.size();j++){
            pervMax = max(pervMax, arr[j]);
        }
        arr[i] = pervMax;
    }
    arr[arr.size()-1] = -1;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}