class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size() , ans = 0;
        bool above = false , left = false;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                above = false , left = false;
                if(i){
                    if(board[i-1][j] == 'X')    above = true;
                }  
                if(j){
                    if(board[i][j-1] == 'X')    left = true;
                } 
                if(!above and !left and board[i][j] == 'X') ans++;
            }
        }
        return ans;
    }
};