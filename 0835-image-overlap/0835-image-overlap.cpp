class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size() , result = 0;
        int x, y;
        for(int i = -n + 1 ; i < n ; i++){
            for(int j = -n + 1 ; j < n ; j++){
                int ans = 0;
                for(int k = 0 ; k < n ; k++){
                    for(int l = 0 ; l < n ; l++){
                        x = l - i;
                        y = k - j;
                        if(x >= 0 and x < n and y >= 0 and y < n){
                            if(img1[x][y] && img2[l][k])    ans++;
                        }
                    }
                }
                result = max(result,ans);
            }
        }
        return result;
    }
};