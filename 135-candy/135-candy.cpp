class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> v(n, 1);
        for(int i=0;i<n;i++){
            if(i==0){
                if(ratings[i]>ratings[i+1]){
                    v[i] = v[i+1]+1;
                }
            }else if(i == n-1){
                if(ratings[i-1]<ratings[i]){
                    v[i] = v[i-1]+1;
                }
            }else{
                if(ratings[i]>ratings[i+1] and ratings[i]>ratings[i-1]){
                    v[i] = (ratings[i+1]>ratings[i-1])? v[i+1]+1 : v[i-1]+1;
                }else if(ratings[i]>ratings[i+1]){
                    v[i] = v[i+1]+1;
                }else if(ratings[i]>ratings[i-1]){
                    v[i] = v[i-1]+1;
                }
            }
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        for(int i=n-1;i>=0;i--){
            if(i==0){
                if(ratings[i]>ratings[i+1]){
                    v[i] = v[i+1]+1;
                }
            }else if(i == n-1){
                if(ratings[i-1]<ratings[i]){
                    v[i] = v[i-1]+1;
                }
            }else{
                if(ratings[i]>ratings[i+1] and ratings[i]>ratings[i-1]){
                    v[i] = (v[i+1]>v[i-1])? v[i+1]+1 : v[i-1]+1;
                }else if(ratings[i]>ratings[i+1]){
                    v[i] = v[i+1]+1;
                }else if(ratings[i]>ratings[i-1]){
                    v[i] = v[i-1]+1;
                }
            }
            cout<<v[i]<<" ";
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};