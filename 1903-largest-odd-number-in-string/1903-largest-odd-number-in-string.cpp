class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() , x = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if((num[n-i]-'0')%2){
                x = i;
                break;
            }
        }
        if(x == 0)  return "";
        return num.substr(0,n-x+1);
    }
};