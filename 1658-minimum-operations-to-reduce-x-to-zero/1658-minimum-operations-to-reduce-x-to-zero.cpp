class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() , ans = INT_MAX , val , search , idx;
        vector<int> p(n+1,0) , s(n+1,0);
        for(int i = 0 ; i < n ; i++){
            p[i+1] = p[i] + nums[i];
            s[i+1] = s[i] + nums[n-i-1];
        } 
        for(int i = 0 ; i <= n ; i++){
            val = p[i];
            search = x - p[i];
            if(search < 0)  break;
            auto it = upper_bound(s.begin(),s.end(),search);
            idx = it - s.begin();
            if(idx < 0 or idx > n)  continue;
            if(val + s[idx-1] == x){
                ans = min(ans,i+idx-1);
            }
        }
        return (ans == INT_MAX or ans > n) ? -1 : ans;
    }
};