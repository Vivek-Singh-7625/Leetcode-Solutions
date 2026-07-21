class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0 , n = s.length() , i = 0 , l = 0 , l2 = INT_MIN , t = INT_MIN;
        vector<int> temp;
        while(i < n){
            while(i < n and s[i] == '1')  ans++ , i++;
            while(i < n and s[i] == '0')  l++ , i++;
            if(l)   temp.push_back(l);
            l = 0;
        }
        int x = temp.size();
        for(int i = 1 ; i < x ; i++){
            t = max(t,temp[i] + temp[i-1]);
        }
        if(t > 0)   return ans + t;
        return ans;
    }
};