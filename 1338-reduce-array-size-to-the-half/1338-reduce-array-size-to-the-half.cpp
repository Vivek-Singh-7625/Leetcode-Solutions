class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int n = arr.size() , x = arr[0] , y = 0 , t = 0;
        for(int i = 0 ; i < n ; i++){
            if(x != arr[i]){
                x = arr[i];
                ans.push_back(y);
                y = 0;
            }
            y++;
        }
        if(y)   ans.push_back(y);
        y = 0;
        sort(ans.begin(),ans.end());
        for(int i = ans.size() - 1 ; i >= 0 ; i--){
            if(y < (n+1)/2) y += ans[i];
            else    break;
            t++;
        }
        return t;
    }
};