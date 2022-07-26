class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int l=0,r=0;
        map<int, int> mp;
        int n=cards.size();
        int c=0;
        int mn = INT_MAX;
        while(r<n){
            mp[cards[r]]++;
            c++;
            while(mp[cards[r]] > 1){
                mn = min(c, mn);
                mp[cards[l]]--;
                c--;l++;
            }
            r++;
        }
        return (mn == INT_MAX) ? -1 : mn;
    }
};