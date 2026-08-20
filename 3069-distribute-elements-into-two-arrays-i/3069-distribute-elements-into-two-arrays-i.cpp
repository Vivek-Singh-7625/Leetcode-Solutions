class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size() , x = 0 , y = 1;
        vector<int> a , b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i = 2 ; i < n ; i++){
            if(nums[x] > nums[y]){
                x = i;
                a.push_back(nums[i]);
            }
            else{
                y = i;
                b.push_back(nums[i]);
            }
        }
        x = a.size();
        for(int i = 0 ; i < x ; i++)   nums[i] = a[i];
        for(int i = x ; i < n ; i++)  nums[i] = b[i-x];
        return nums;
    }
};