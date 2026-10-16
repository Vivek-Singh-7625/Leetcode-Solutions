class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = y.size() , y1 = -1, y2 = -1, y3 = -1;
        int x1 = 0, x2 = 0, x3 = 0 , k ;
        for(int i = 0; i < n; i++) {
            if(x[i] == x1) {
                if(y[i] > y1) y1 = y[i];
            } 
            else if(x[i] == x2) {
                if(y[i] > y2) y2 = y[i];
            } 
            else if(x[i] == x3) {
                if(y[i] > y3) y3 = y[i];
            } 
            else if(y[i] > y1 or y[i] > y2 or y[i] > y3) {
                k = min(y1,min(y2, y3));
                if(k == y1) {
                    y1 = y[i];
                    x1 = x[i];
                } 
                else if(k == y2) {
                    y2 = y[i];
                    x2 = x[i];
                } 
                else {
                    y3 = y[i];
                    x3 = x[i];
                }
            }
        }
        if(y1 == -1 || y2 == -1 || y3 == -1)    return -1;
        return y1 + y2 + y3;
    }
};