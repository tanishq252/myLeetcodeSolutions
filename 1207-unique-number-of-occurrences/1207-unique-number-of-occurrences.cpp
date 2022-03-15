class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        vector<int> v;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(int i=*min_element(arr.begin(), arr.end());i<=*max_element(arr.begin(), arr.end());i++){
            if(m[i]>0){v.push_back(m[i]);}
        }
        sort(v.begin(), v.end());
        for(int i=1;i<v.size();i++){
            if(v[i-1]==v[i]){return false;}
        }
        return true;
    }
};