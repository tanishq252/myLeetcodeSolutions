#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,3,3,4};
    int counter = 1;
    for (int i=1;i<v.size();i++){
        if(v[i]!=v[i-1]){
            v[counter++] = v[i];
        }
    }
    v.shrink_to_fit();
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    cout<<counter;
}

// accepted