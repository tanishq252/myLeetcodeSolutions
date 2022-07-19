class Solution {
public:
    void rotateArray(vector<int> &vec, int x){
        for(int m=0;m<x;m++){
            vector<int> vec2(vec.size(), 0);
            int j=1;
            for(int i=0;i<vec.size()-1;i++){
                vec2[j++] = vec[i];
            }
            vec2[0] = vec[vec.size()-1];
            vec = vec2;
            }
    }
    
    void storeMat(vector<vector<int>> &matrix,int startx, int starty, int endx, int endy){
        vector<int> vec;
        if(startx >= endx) return;
        int i=startx, j=starty;
        while(j<=endy){
            vec.push_back(matrix[i][j++]);
        }
        i++;
        j--;
        while(i<=endx){
            vec.push_back(matrix[i++][j]);
        }
        i--;
        j--;
        while(j>=starty){
            vec.push_back(matrix[i][j--]);
        }
        j++;
        i--;
        while(i>startx){
            vec.push_back(matrix[i--][j]);
        }
        rotateArray(vec, endx-startx);        
        rotateMat(matrix, vec, startx, starty, endx, endy);
    }
    
    void rotateMat(vector<vector<int>> &matrix,vector<int> &vec, int startx, int starty, int endx, int endy){
        int i=startx, j=starty, k=0;
        while(j<=endy){
            matrix[i][j++] = vec[k++];
        }
        i++;
        j--;
        while(i<=endx){
            matrix[i++][j] = vec[k++];
        }
        j--;
        i--;
        while(j>=starty){
            matrix[i][j--] = vec[k++];
        }
        j++;
        i--;
        while(i>startx){
            matrix[i--][j] = vec[k++];
        }
        storeMat(matrix, startx+1, starty+1, endx-1, endy-1);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        storeMat(matrix, 0, 0, matrix.size()-1, matrix.size()-1);
    }
};