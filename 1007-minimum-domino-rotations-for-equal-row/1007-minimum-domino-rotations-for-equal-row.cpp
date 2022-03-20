class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int, int> m{{1,0},{2,0},{3,0},{4,0},{5,0},{6,0}};
        if(tops == bottoms){return 0;}
        for(int i=0;i<tops.size();i++){
            m[tops[i]]++;
            m[bottoms[i]]++;
        }
        int ele=0, ans=0;
        for(int i=1;i<=6;i++){
            if(m[i]>=tops.size()){ele = i;}
        }
        if(ele==0){return -1;}
        if(count(tops.begin(), tops.end(), ele)<count(bottoms.begin(), bottoms.end(), ele)){swap(tops, bottoms);}
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=ele){
                if(bottoms[i]==ele){
                    ans++;
                    swap(tops[i], bottoms[i]);
                }
            }
        }
        set<int> st(tops.begin(), tops.end());
        return (st.size()==1)?ans:-1;
    }
};