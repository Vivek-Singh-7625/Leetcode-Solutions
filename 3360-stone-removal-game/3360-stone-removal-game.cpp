class Solution {
public:
    bool canAliceWin(int n) {
        int t = 11;
        while(t--){
            if(n >= t)  n -= t;
            else    break;
        }
        return t%2;
    }
};