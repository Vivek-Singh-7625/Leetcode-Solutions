class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size() , n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] != word[0])    continue;
                if(dfs(board,word,i,j,0))   return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word , int i , int j , int k){
        if(k == word.size())    return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())  return false;
        char x = board[i][j];
        if(x != word[k])    return false;
        board[i][j] = '0';
        bool ans = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j-1,k+1) || dfs(board,word,i,j+1,k+1);   
        board[i][j] = x;
        return ans;
    }
};