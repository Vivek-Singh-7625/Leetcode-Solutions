class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3)    return nums[0]*nums[1]*nums[2];    
        int a = INT_MIN , b = INT_MIN , c = INT_MIN;
        int d = INT_MAX , e = INT_MAX , f = INT_MAX , n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(a < nums[i]){
                c = b;
                b = a;
                a = nums[i];
            }
            else if(b < nums[i]){
                c = b;
                b = nums[i];
            }
            else if(c < nums[i])    c = nums[i];
            if(d > nums[i]){
                f = e;
                e = d;
                d = nums[i];
            }
            else if(e > nums[i]){
                f = e;
                e = nums[i];
            }
            else if(f > nums[i])    f = nums[i];
        }
        return max(a*b*c,d*e*a);
    }
};