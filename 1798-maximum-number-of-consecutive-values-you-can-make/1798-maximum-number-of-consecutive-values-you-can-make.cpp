class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        int range = 0 , i = 0 ;
        while(i < n){
            if(i < n and coins[i] <= range+1)   range += coins[i];
            else    break;
            i++;
        }
        return range + 1;
    }
};