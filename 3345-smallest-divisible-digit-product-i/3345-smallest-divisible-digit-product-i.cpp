class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0 , x , y ;
        for(int i = n ; i < n+10 ; i++){
            x = i;
            y = 1;
            while(x){
                y = y*(x%10);
                x = x/10;
            }
            if(y%t == 0)    return i;
        }
        return -1;
    }
};