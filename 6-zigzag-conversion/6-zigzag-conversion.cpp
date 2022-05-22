class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1){return s;}
        int len = s.size();
        if(numRows>=len){return s;}
        vector<string> mat(min(numRows, len));
        int currentRow = 0;
        bool goingDown = false;
        for(auto i:s){
            mat[currentRow]+=i;
            if(currentRow == 0 || currentRow == numRows-1) goingDown = !goingDown;
            currentRow+= (goingDown) ? 1:-1;
        }
        string ans="";
        for(auto i:mat){
            ans+=i;
        }
        return ans;
        // passed 909/1157 cases
        // if(numRows == 1){return s;}
        // int len = s.size();
        // if(numRows>=len){return s;}
        // vector<vector<string>> mat(numRows, vector<string>(len));
        // int i=0, x=0, y=0, c=0, k=0;
        // while(i<len){
        //     mat[x++][y] = s[i++];
        //     c++;
        //     if(c%numRows==0){
        //         k = numRows-2;
        //         x-=2;
        //         y++;
        //         while(k-- and i<len){
        //             mat[x--][y++] = s[i++];
        //         }
        //     }
        // }
        // string ans="";
        // for(int i=0;i<numRows;i++){
        //     for(int j=0;j<len;j++){
        //         cout<<mat[i][j]<<"\t";
        //         if(mat[i][j]!="") ans+=mat[i][j];
        //     }
        //     cout<<"\n";
        // }
        // return ans;
    }
};