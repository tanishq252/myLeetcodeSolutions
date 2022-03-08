class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        map<string, int> m;
        vector<string> v;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m[arr[i]] == 1){v.push_back(arr[i]);}
        }
        return k>v.size() ? "": v[k-1];
    }
};