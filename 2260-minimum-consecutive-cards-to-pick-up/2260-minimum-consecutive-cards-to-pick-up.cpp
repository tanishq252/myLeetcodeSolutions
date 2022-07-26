class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        //this approach is using sliding window 
        //left and right pointers
        int l=0,r=0;
        //map for frequency
        map<int, int> mp;
        int n=cards.size();
        //count when there are two cards in given sub array
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