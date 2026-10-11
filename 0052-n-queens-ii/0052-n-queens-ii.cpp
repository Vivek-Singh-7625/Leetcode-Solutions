class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> q(n,vector<bool> (n,false));
        int ans = 0;
        for(int i = 0 ; i < n ; i++)    helper(0,i,q,ans);
        return ans/n;
    }
    void helper(int x , int y , vector<vector<bool>>& q , int& ans){
        if(x == q.size()){
            ans++;
            return;
        }
        if(not_valid(x,y,q))    return;
        q[x][y] = true;
        for(int i = 0 ; i < q.size() ; i++)    helper(x+1,i,q,ans);
        q[x][y] = false;;
    }
    bool not_valid(int x , int y , vector<vector<bool>>& q){
        int n = q.size();
        for(int i = 0 ; i < x ; i++){
            if(q[i][y]) return true;
        }
        for(int i = x-1 , j = y-1 ; i >= 0 && j >= 0; i-- , j--){
            if(q[i][j]) return true;
        }
        for(int i = x-1 , j = y+1 ; i >= 0 && j < n ; i-- , j++){
            if(q[i][j]) return true;
        }
        return false;
    }
};