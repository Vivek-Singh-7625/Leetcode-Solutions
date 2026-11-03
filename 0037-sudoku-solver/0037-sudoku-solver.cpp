class Solution {
public:
    bool isSafe(vector<vector<char>>& b, int x, int y, int num) {
        for(int i = 0; i < 9; i++){
            if(b[x][i] - '0' == num)    return false;
        }
        for(int i = 0; i < 9; i++){
            if(b[i][y] - '0' == num)    return false;
        }
        int r = (x/3)*3, c = (y/3)*3;
        for(int i = r; i < r+3; i++){
            for(int j = c; j < c+3; j++){
                if(b[i][j] - '0' == num)    return false;
            }
        }
        return true;
    }

    bool solver(vector<vector<char>>& b, int p) {
        if(p == 81)   return true;
        int x = p/9, y = p%9;
        if(b[x][y] != '.')  return solver(b,p+1);

        char t;
        for(int i = 1; i <= 9; i++){
            if(isSafe(b,x,y,i)){
                t = '0' + i;
                b[x][y] = t;
                if(solver(b,p+1))   return true;
                b[x][y] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0);
        return;
    }
};