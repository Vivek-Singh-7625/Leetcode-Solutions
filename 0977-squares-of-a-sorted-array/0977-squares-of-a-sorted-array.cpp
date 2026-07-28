class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int x = 0 , n = nums.size() , y = 0 , k = 0;
        vector<int> A(n,0);
        while(x < n and nums[x] < 0)  x++;
        y = x-1;
        for(int i = 0 ; i < n ; i++){
            if(x < n and y >= 0){
                if(nums[x] > abs(nums[y]))  A[k++] = nums[y]*nums[y--];
                else    A[k++] = nums[x]*nums[x++] ;
            }
            else if(x < n)  A[k++] = nums[x]*nums[x++];
            else    A[k++] = nums[y]*nums[y--];
        }
        return A;
    }
};