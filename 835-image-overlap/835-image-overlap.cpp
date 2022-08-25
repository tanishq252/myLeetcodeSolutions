class Solution {
public:
    int shiftAndCount(vector<vector<int>>& img1, vector<vector<int>>& img2, int xshift, int yshift){
        int leftcount = 0, rightcount = 0;
        int n = img1.size();
        for(int img1row = yshift, img2row = 0; img1row<n;img1row++, img2row++){
            for(int img1col = xshift, img2col = 0; img1col < n; img1col++, img2col++){
                if(img1[img1row][img1col] == 1 and img1[img1row][img1col] == img2[img2row][img2col]){
                    leftcount++;
                }
                if(img1[img1row][img2col] == 1 and img1[img1row][img2col] == img2[img1row][img2col]){
                    rightcount++;
                }
            }
        }
        return max(leftcount, rightcount);
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> LA, LB;
        int N = A.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N * N; ++i)
            if (A[i / N][i % N] == 1)
                LA.push_back(i / N * 100 + i % N);
        for (int i = 0; i < N * N; ++i)
            if (B[i / N][i % N] == 1)
                LB.push_back(i / N * 100 + i % N);
        for (int i : LA) for (int j : LB) count[i - j]++;
        int res = 0;
        for (auto it : count) res = max(res, it.second);
        return res;
        // int maxOverlaps = 0;int n = img1.size();
        // for(int yshift=0;yshift<n;yshift++){
        //     for(int xshift=0;xshift<n;xshift++){
        //         maxOverlaps = max(maxOverlaps, shiftAndCount(img1, img2, xshift, yshift));                                   maxOverlaps = max(maxOverlaps, shiftAndCount(img2, img1, xshift, yshift));
        //     }
        // }
        // return maxOverlaps;
    }
};