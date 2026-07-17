class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0 ;
        long long temp = n;
        while(temp != 1){
            if(temp%4 == 1 or temp == 3)    temp--;
            else if(temp%4 == 3)   temp++;
            else temp = temp/2;
            ans++;
        }
        return ans;
    }
};