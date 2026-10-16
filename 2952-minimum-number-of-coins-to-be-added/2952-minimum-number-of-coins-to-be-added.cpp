class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size() , i = 0 , ans = 0;
        long long range = 0;
        sort(coins.begin(),coins.end());
        while(range < target){
            if(i < n and coins[i] <= range + 1){
                range += coins[i];
                i++;
            }
            else{
                ans++;
                range = (2*range + 1);
            }
        }
        return ans;
    }
};