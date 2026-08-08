class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> t(8,0);
        n = n%14;
        if (n == 0) n = 14;
        for(int i = 0 ; i < n ; i++){
            for(int i = 1 ; i < 7 ; i++){
                if(cells[i-1] != cells[i+1])    t[i] = 0;
                else    t[i] = 1;
            }
            cells = t;
        }
        return cells;
    }
};