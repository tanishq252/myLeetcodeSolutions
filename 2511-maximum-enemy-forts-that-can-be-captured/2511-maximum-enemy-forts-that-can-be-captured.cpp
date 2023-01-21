class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(forts[i]==-1){
                int j=i+1;

                while(forts[j]==0 and j<n){
                    j++;
                    if(j==n) break;
                    if(forts[j]==1){
                        ans = max(ans, j-i);
                        i=j-1;
                    }else if(forts[j]==-1){
                        i=j-1;
                        break;
                    }
                }
            }
            if(forts[i]==1){
                int j=i+1;
                while(forts[j]==0 and j<n){
                    j++;
                    if(j==n) break;
                    if(forts[j]==-1){
                        ans = max(ans, j-i);
                        i=j-1;
                    }else if(forts[j]==1){
                        i=j-1;
                        break;
                    }
                }
            }
        }
        return ans!=INT_MIN?ans-1:0;
    }
};