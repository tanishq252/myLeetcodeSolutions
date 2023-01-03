// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/submissions/869549941/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res=1;
        unordered_map<int, int> mp;
        for(auto &i:arr){
            res = max(res, mp[i]=1+mp[i-difference]);
        }
        return res;
    }
    
    // 36/39 passed
    // unordered_map<int, vector<int>> mp;
    // int mx=1;

    // void mxSeq(vector<int>& arr, int difference, int ele, int in, vector<int> &v){
    //     int k=ele+difference;
    //     if(in == arr.size()) return;
    //     if(mp.find(k)!=mp.end()){
    //         int ind=lower_bound(mp[k].begin(), mp[k].end(), in+1)-mp[k].begin();
    //         if(ind < mp[k].size() ){
    //             v.push_back(k);
    //             // cout<<k<<" "<<mp[k][ind]<<"\n";
    //             mxSeq(arr, difference, k, mp[k][ind], v); 
    //         }
    //         if(ind == mp[k].size()) return;
    //     }else{
    //         return;
    //     }

    // }

    // int longestSubsequence(vector<int>& arr, int difference) {
    //     for(int i=0;i<arr.size();i++) mp[arr[i]].push_back(i);
    //     int m=1;
    //     if(difference==0){
    //         for(auto &i:mp){
    //              if(m < i.second.size()) m=i.second.size();
    //         }
    //         return m;
    //     }
    //     int n=arr.size(),len=1;
    //     vector<int> dp(n,1);
    //     for(int i=0;i<n;i++){
    //         vector<int> v;
    //         v.push_back(arr[i]);
    //         mxSeq(arr, difference, arr[i], i, v);
    //         mx = max(mx, (int)v.size());
    //     }
    //     return mx;
    // }
};