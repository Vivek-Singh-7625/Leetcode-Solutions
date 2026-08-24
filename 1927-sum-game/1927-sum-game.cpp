class Solution {
public:
    bool sumGame(string num) {
        int a = 0 , b = 0 , c = 0 , d = 0 , n = num.length() , x = 1 , e = 0 , f = 0;
        for(int i = 0 ; i < n ; i++){
            if(num[i] >= '0' and num[i] <= '9'){
                if(i < n/2) a += (num[i] - '0');
                else    b += (num[i] - '0');
            }
            else{
                if(i < n/2){
                    if(x)   c++;
                    else    d++;
                }
                else{
                    if(x)   e++;
                    else    f++;
                }
                x = x^1;
            }
        }
        return (a + c*9 != b + f*9) || (a + d*9 != b + e*9);
    }
};