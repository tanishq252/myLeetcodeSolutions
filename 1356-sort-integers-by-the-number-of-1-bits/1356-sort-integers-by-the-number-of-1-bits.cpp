class Solution {
public:
    int bc(int n){
        int i = 0;
        while(n>0){
            i+= (n%2==1)?1:0;
            n/=2;
        }
        return i;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> v;
        vector<pair<int, int>> vec;
        map<int, int> m;
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            vec.push_back(make_pair(bc(arr[i]), arr[i]));
        }
        sort(vec.begin(), vec.end());
        for(int i=0;i<vec.size();i++){
            v.push_back(vec[i].second);
        }
        return v;

    }
};