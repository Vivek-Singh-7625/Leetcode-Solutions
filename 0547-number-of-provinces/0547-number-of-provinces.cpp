class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0 , n = isConnected.size();
        vector<bool> visited(n,false);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                traversal(i,visited,isConnected);
                ans++;
            }
        }
        return ans;
    }
    void traversal(int x , vector<bool>& v, vector<vector<int>>& a){
        if(v[x])    return;
        v[x] = true;
        for(int i = 0 ; i < a.size() ; i++){
            if(a[x][i]){
                traversal(i,v,a);
                v[i] = true;
            }
        }
    }
};