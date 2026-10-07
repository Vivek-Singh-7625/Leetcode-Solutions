class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> A;
        string t = "";
        for(int i = 0 ; i < n ; i++)    t += '.';
        for(int i = 0 ; i < n ; i++)    A.push_back(t);
        for(int i = 0 ; i < n ; i++){
            helper(ans,A,0,i);
        }
        return ans;
    }
    bool filler(vector<string>& A , int x , int y){
        int n = A.size();

        for(int i = 0 ; i < x ; i++){
            if(A[i][y] == 'Q')  return true;
        }
        for(int i = x-1 , j = y-1 ; i >= 0 and j >= 0 ; i-- , j--){
            if(A[i][j] == 'Q')  return true;
        }
        for(int i = x-1 , j = y+1 ; i >= 0 and j < n ; i-- , j++){
            if(A[i][j] == 'Q')  return true;
        }

        return false;
    }
    void helper(vector<vector<string>>& ans , vector<string>& A , int x , int y){
        if(x == A.size()){
            ans.push_back(A);
            return;
        };
        if(filler(A , x , y))   return;
        A[x][y] = 'Q';
        if(x == A.size() - 1){
            ans.push_back(A);
        }
        else {
            for(int i = 0; i < A.size(); i++){
                helper(ans, A, x + 1, i);
            }
        }
        A[x][y] = '.';
    }
};