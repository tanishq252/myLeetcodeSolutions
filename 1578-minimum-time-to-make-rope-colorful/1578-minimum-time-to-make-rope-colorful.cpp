class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0, n = colors.length();
        if(n==1) return ans;
        int x, y;
        for(int i=0;i<n-1;i++){
            if(colors[i] == colors[i+1]){
                x = i;
                while(colors[i] == colors[i+1] and i<n-1) i++;
                y = i;
                int s = accumulate(neededTime.begin()+x, neededTime.begin()+y+1, 0);
                int m = *max_element(neededTime.begin()+x, neededTime.begin()+y+1);
                ans+=(s-m);
                cout<<x<<" "<<y<<" "<<s<<" "<<m<<"\n";
            }
        }
        return ans;
    }
};