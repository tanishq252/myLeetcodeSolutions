class Solution {
public:
    bool squareIsWhite(string coordinates) {
        cout<<'h'-'a'<<'8'-'0';
        if((coordinates[0]-'a')%2==0 && (coordinates[1]-'0')%2==0){return true;}
        else if((coordinates[0]-'a')%2==0 && (coordinates[1]-'0')%2!=0){return false;}
        else if((coordinates[0]-'a')%2!=0 && (coordinates[1]-'0')%2!=0){return true;}
        else if((coordinates[0]-'a')%2!=0 && (coordinates[1]-'0')%2==0){return false;}


        return false;
    }
};