class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp1;        
        unordered_map<string, int> mp2;
        unordered_map<string, int> mp;
        string s = "AA";
        int mx = INT_MIN;
        for(auto &i:words) mp[i]++;
        for(auto &i:words){
            if(i[0] == i[1]){
                mp2[i]++;
            }else{
                s[0] = i[1];
                s[1] = i[0];
                if(mp.find(s)!=mp.end()){
                    mp1[i]++;
                }
            }
        }
        int dub=0;
        for(auto &i:mp2){
            if(i.second%2==0){
                dub+=i.second;
            }else{
                mx = max(mx, i.second);
            }
        }
        int flag=0;
        for(auto &i:mp2){
            if(i.second!=mx and i.second%2==1){
                dub+=(i.second-1);
            }
            if(i.second==mx){
                if(flag==0){
                    flag=1;
                    dub+=mx;
                }else{
                    dub+=(mx-1);
                }
            }
            
        }
        for(auto &i:mp1){
            s[0]=i.first[1];s[1]=i.first[0];
            dub+=(min(mp1[i.first], mp1[s]));
        }
        mx = mx==INT_MIN ? 0:mx;
        return 2*(dub);
    }
};