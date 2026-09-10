class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long a1 = 1 , a2 = INT_MIN;
        int x = INT_MIN , l = 0 , p = 0;
        bool isz = true , isp = false , z = false;
        if(nums.size() == 1)    return nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]){ 
                a1 = a1*nums[i];
                isp = true , isz = false;
                if(nums[i] < 0){ 
                    x = max(x,nums[i]);
                    l++;
                }
                else p++;
            }
            else    z = true;
        }
        if(isz) return 0;
        if(l > 1)   a2 = max(a1,a1/x);
        if(p)   a2 = max(a1,a1/x); 
        if(z)   a2 = max(a2,0ll); 
        a2 = max(a2,a1); 
        return a2;
    }
};