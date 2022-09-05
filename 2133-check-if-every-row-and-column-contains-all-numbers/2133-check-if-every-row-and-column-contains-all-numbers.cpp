class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rows(n);        
        vector<int> cols(n);
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=0;j<n;j++){
                st.insert(mat[i][j]);
            }
            rows[i] = st.size();
            st.clear();
            for(int j=0;j<n;j++){
                st.insert(mat[j][i]);
            }
            cols[i] = st.size();
        }
        for(int i=0;i<n;i++){
            if(cols[i]!=n or rows[i]!=n){
                return false;
            }
        }
        return true;
    }
};