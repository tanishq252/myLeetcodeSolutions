class Solution {
public:
    vector<int> side = {0,0,0,0};
    int squareSide;
    
    bool dfs(int ind, vector<int> &matchSticks){
        if(ind == matchSticks.size()) {
            return side[0]==side[1] and side[1]==side[2] and side[3]==side[2];
        }
        
        //try to add the sticks to 4 sides
        for(int i=0;i<4;i++){
            if(side[i]+matchSticks[ind] <= squareSide){
                
                side[i]+=matchSticks[ind];
                // cout<<side[i]<<" ";
                if(dfs(ind+1, matchSticks)) return true;
                //backtracking
                side[i]-=matchSticks[ind];
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        sort(matchsticks.begin(), matchsticks.end(), [](int a, int b){
            return a>b;
        });
        
        int s = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if((s/4)*4 != s) return false;
        
        squareSide = s/4;
        
        return dfs(0, matchsticks);
        
    }
};