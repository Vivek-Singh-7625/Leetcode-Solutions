class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> A(n,0) , B(n,0);
        int ans = 0;
        A[0] = height[0];
        B[n-1] = height[n-1];
        for(int i = 1 ; i < n ; i++)    A[i] = max(A[i-1],height[i]);
        for(int i = n - 2 ; i >= 0 ; i--)  B[i] = max(height[i],B[i+1]);
        for(int i = 0 ; i < n ; i++)    ans += (min(A[i],B[i])-height[i]);
        return ans;
    }
};