class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0 , b = 0 , c = 0 , n = bills.size() , cash;
        for(int i = 0 ; i < n ; i++){
            cash = bills[i];
            if(cash == 5)   a++;
            else if(cash == 10){
                b++;
                a--;
            }
            else{
                if(b and a) b--,a--;
                else    a -= 3;
            }
            if(a < 0 or b < 0 or c < 0) return false;
        }
        return true;
    }
};