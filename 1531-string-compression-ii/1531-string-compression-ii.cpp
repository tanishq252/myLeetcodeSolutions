class Solution {
    const static int N = 127;

    // dp[left][k] means the minimal coding size for substring 
    // s[left:] and removing at most k chars
    int dp[N][N];

    string str;
    int n;

    // get length of digit
    inline int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }

    int solve(int left, int k) {
        if(k < 0) return N;  // invalid, return INF
        if(left >= n or n - left <= k) return 0;  // empty

        int& res = dp[left][k];
        if(res != -1) return res;
        res = N;

        int cnt[26] = {0};
        // we try to make s[left:j] (both inculded) as one group,
        // and all chars in this group should be the same.
        // so we must keep the most chars in this range and remove others
        // the range length is (j - left + 1)
        // and the number of chars we need to remove is (j - left + 1 - most)
        for(int j = left, most = 0; j < n; j++) {
            most = max(most, ++cnt[str[j] - 'a']);  // most = max(count(s[left:j])
            res = min(res, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        str = s;
        n = s.size();
        return solve(0, k);
    }
};


// proud to solve half test cases :)
// class Solution {
// public:
//     int getLengthOfOptimalCompression(string s, int k) {
//         vector<int> f(26, 0);
//         for(auto &i:s) f[i-'a']++;
//         vector<pair<int, int>> vec;
//         for(int i=0;i<26;i++){
//             if(f[i]>0) vec.push_back({f[i], i});
//         }
//         sort(vec.begin(), vec.end());
//         int ans=0, tempK;
//         string ss,s1;
//         bool b=false;
//         for(auto i:vec){
//             if(k>0){
//                 if(i.first<=k){
//                     k-=i.first;
//                 }else{
//                     tempK=k;
//                     ss = to_string(i.first-k);
//                     if(ss == "1" or ss=="0"){
//                         if(ss=="0"){
//                             b=true;
//                         }else if(ss=="1"){
//                             b = true;
//                             ans++;
//                         }
//                     }
//                     else{
//                         ans+=(ss.length()+1);
//                     }
//                     k-=i.first;
//                 }
//             }else{
//                 if(!b){
//                     ss = to_string(i.first-tempK);
//                     s1 = to_string(i.first);
//                     if(s1.length()-ss.length() == 1){
//                         ans--;
//                         b = true;
//                     }
//                 }
//                 ss = to_string(i.first);
//                 ans+=(ss=="1")?1:(ss.length()+1);
//             }
//         }
//         return ans;
//     }
// };