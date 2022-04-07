class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        if(v.size() == 1){return v[0];}
        sort(v.begin(), v.end());
        while(v.size()>1){
            if(v[v.size()-1]>v[v.size()-2]){
                int j = v[v.size()-1] - v[v.size()-2];
                v.pop_back();            
                v.pop_back();
                v.push_back(j);
            }
            else if(v[v.size()-1]==v[v.size()-2]){
                v.pop_back();            
                v.pop_back();
            }
            sort(v.begin(), v.end());
            cout<<v[0]<<" "<<v.size()<<"\n";
            if(v.size() == 0){return 0;}
        }
        return v[0];
    }
};