#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> heights = {5,1,2,3,4};
    sort( heights.begin(),heights.end());
    reverse( heights.begin(),heights.end());
    for(int i=0;i<heights.size();i++){
        cout<<heights[i]<<" ";
    }
}