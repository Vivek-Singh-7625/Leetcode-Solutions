class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n = matrix[0].size();
        int low = 0 , high = m*n-1 , x , y , mid;
        while(low <= high){
            mid = low + (high-low)/2;
            x = mid/n;
            y = mid%n;
            cout << matrix[x][y] << endl;
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] > target)  high = mid - 1;
            else    low = mid + 1;
        }
        return false;
    }
};