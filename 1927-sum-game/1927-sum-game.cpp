class Solution {
public:
    bool sumGame(string num) {
        int a = 0 , b = 0 , c = 0 , d = 0 , n = num.length();
        for(int i = 0 ; i < n ; i++){
            if(num[i] != '?'){
                if(i < n/2) a += (num[i] - '0');
                else    b += (num[i] - '0');
            }
            else{
                if(i < n/2) c++;
                else    d++;
            }
        }
        return (c+d)&1 || (2*(a-b) != 9*(d-c));
    }
};