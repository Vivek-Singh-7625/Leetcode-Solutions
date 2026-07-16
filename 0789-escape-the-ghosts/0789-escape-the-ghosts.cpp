class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int pac = abs(target[0]) + abs(target[1]);
        int n = ghosts.size();
        int gh = INT_MAX;
        for(int i = 0 ; i < n ; i++)    gh = min(gh , abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1]));
        return pac < gh;
    }
};