// https://leetcode.com/contest/biweekly-contest-95/problems/categorize-box-according-to-criteria/

class Solution {
public:
    
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky=false, isHeavy=false;
        int k=10000, v = 1000000000;
        long long vol = (long long)length*width*height;
        if(length >= k or width >= k or height >= k or mass >= k or vol>=v) isBulky = true;
        if(mass>=100) isHeavy=true;
        if(isHeavy and isBulky){
            return "Both";
        }
        else if(isBulky){
            return "Bulky";
        }else if(isHeavy){
            return "Heavy";
        }
        return "Neither";
    }
};