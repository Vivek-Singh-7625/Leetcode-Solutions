class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size() , result = 0;;
        vector<vector<int>> ov(n,vector<int> (n));
        for(int i = -n + 1 ; i < n ; i++){
            for(int j = -n + 1 ; j < n ; j++){
                for(int k = 0 ; k < n ; k++){
                    vector<int> t(n,0);
                    for(int l = 0 ; l < n ; l++){
                        if(l-i >= 0 and l - i < n) t[l-i] = img1[k][l];
                    }
                    ov[k] = t;
                }
                int ans = 0;
                for(int k = 0 ; k < n ; k++){
                    vector<int> t(n,0);
                    for(int l = 0 ; l < n ; l++){
                        if(l-j >= 0 and l - j < n) t[l-j] = ov[l][k];
                    }
                    for(int l = 0 ; l < n ; l++){
                        ov[l][k] = t[l];
                    }
                }
                for(int k = 0 ; k < n ; k++){
                    for(int l = 0 ; l < n ; l++){
                        if(ov[l][k] == img2[l][k] and ov[l][k])  ans++;
                    }
                }
                result = max(result,ans);
            }
        }
        return result;
    }
};