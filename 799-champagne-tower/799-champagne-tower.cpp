class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v( 101 , vector<double> (101, 0));
        v[0][0] = (double)poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=query_glass;j++){
                double flow = (v[i][j]-1)/2;
                // as we want equal amount of water flowing after filling the current glass
                if(flow>0){v[i+1][j] += flow;
                v[i+1][j+1] += flow;}
            }
        }
        
        return (v[query_row][query_glass]>1)?1:v[query_row][query_glass];

    }
};