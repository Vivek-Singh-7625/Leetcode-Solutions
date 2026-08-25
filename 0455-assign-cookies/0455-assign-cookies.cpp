class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int y = 0 , ans = 0 , n = g.size() , m = s.size();
        for(int i = 0 ; i < n ; i++){
            while(y < m and s[y] < g[i])    y++;
            if(y == m)  break;
            ans++;
            y++;
        }
        return ans;
    }
};