#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,0,2,3,0,4,5,0};
    for(int i=0;i<v.size();i++){
        if(v[i] == 0){
            v.insert(v.begin()+i,0);
            v.pop_back();
            i++;
        }
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}

// this solution is accepted