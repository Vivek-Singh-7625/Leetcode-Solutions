class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)  return 1;
        if(n == 1)  return x;
        double t = myPow(x,abs(n/2));
        if(n%2){
            if(n < 0)   return 1/(t*t*x);
            return t*t*x;
        }
        if(n < 0)   return 1/(t*t);
        return t*t;
    }
};