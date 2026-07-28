class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int x = 0 , n = nums.size() , k = n;
        int y = n-1;
        vector<int> A(n,0);
        while(x <= y){
            if(abs(nums[x]) < abs(nums[y])) A[--k] = nums[y]*nums[y--];
            else    A[--k] = nums[x]*nums[x++]; 
        }
        return A;
    }
};