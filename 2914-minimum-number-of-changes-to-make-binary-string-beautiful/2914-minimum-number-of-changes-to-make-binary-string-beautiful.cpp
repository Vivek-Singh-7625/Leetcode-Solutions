class Solution {
public:
    int minChanges(string s) {
        int cz = 0 , co = 0 , ans = 0 ;
        for(char c : s){
            if(c == '0'){
                if(cz%2)    ans++ , co--;
                co++;
                cz = 0;
            }
            else{
                if(co%2)    ans++ , cz--;
                cz++;
                co = 0;
            }
        }
        return ans;
    }
};