class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> nums(10,0);
        int ans = 0;
        while(n){
            nums[n%10]++;
            n = n/10;
        }
        for(int i = 0 ; i < 10 ; i++)    ans += i*nums[i];
        return ans;
    }
};