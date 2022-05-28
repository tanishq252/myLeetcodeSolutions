class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center;
        vector<int> m(edges.size()+2, 0);
        for(auto i:edges){
            m[i[0]]++;
            if(m[i[0]]>1) return i[0];
            m[i[1]]++;
            if(m[i[1]]>1) return i[1];
        }
        return 0;

    }
};