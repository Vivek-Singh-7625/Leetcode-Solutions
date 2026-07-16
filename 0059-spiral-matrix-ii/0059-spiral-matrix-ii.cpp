class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int start = 0 , end = n , left = 0 , right = n , k = 1;
        vector<vector<int>> A(n,vector<int> (n));
        while(k <= n*n){
            for(int i = left ; i < right ; i++) A[start][i] = k++;
            start++;
            for(int i = start ; i < end ; i++)  A[i][right-1] = k++;
            right--;
            for(int i = right - 1 ; i >= left ; i--)    A[end-1][i] = k++;
            end--;
            for(int i = end-1 ; i >= start ; i--)   A[i][left] = k++;
            left++;
        }
        return A;
    }
};