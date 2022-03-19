class Solution {
public:
    int countPoints(string rings) {
        map <int, set<char>> m;
        for(int i=0;i<rings.size();i+=2){
            m[rings[i+1]].insert(rings[i]);
        }
        int c=0;
        for(int i=0;i<m.size();i++){
            c+= (m[i].size()==3)?1:0;
        }
        return c;
    }
};