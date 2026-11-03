class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0);
        return;
    }
    bool solver(vector<vector<char>>& b , int p){
        if(p == 81)   return true;
        int x = p/9 , y = p%9;
        if(b[x][y] != '.'){
            return solver(b,p+1);
        }
        char t;
        x = p/9 , y = p%9;
        bool skip;
        for(int i = 0 ; i < 9 ; i++){
            skip = false;
            t = '1' + i;
            for(int j = 0 ; j < 9 ; j++){
                if(j == x)  continue;
                if(b[j][y] == t)    skip = true;
            }
            for(int j = 0 ; j < 9 ; j++){
                if(j == y)  continue;
                if(b[x][j] == t)    skip = true;
            }
            int r = (x/3)*3, c = (y/3)*3;
            for(int i = r; i < r+3; i++){
                for(int j = c; j < c+3; j++){
                    if(i == x and j == y)  continue;
                    if(b[i][j] == t)   skip = true;
                }
            }
            if(skip)    continue;
            b[x][y] = t;
            if(solver(b,p+1)) return true;
            b[x][y] = '.';
        }
        return false;
    }
};