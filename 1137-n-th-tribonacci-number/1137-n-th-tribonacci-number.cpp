class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)  return n;
        int x = 0 , y = 1 , z = 1 , t;
        for(int i = 2; i < n ; i++){
            t = x+y+z;
            x = y;
            y = z;
            z = t;
        }
        return z;
    }
};