class Solution {
public:
    bool scoreBalance(string s) {
        int right = 0 , left = 0;
        for(char c : s){
            right += c-'a'+1;
        } 
        for(char c : s){
            right -= c-'a'+1;
            left += c-'a'+1;
            if(left == right)   return true;
        } 
        return false;
    }
};