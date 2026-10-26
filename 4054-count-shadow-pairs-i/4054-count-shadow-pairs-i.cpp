class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size() , total = 0 , k = 0;
        long long ans = 0 ;
        stack<pair<int,int>> st;
        for(int i = 0 ; i < n ; i++){
            k = nums[i];
            while(!st.empty() && st.top().first > k){
                total -= st.top().second;
                st.pop();
            }
            if(!st.empty() and k == st.top().first)   st.top().second++;
            else    st.push({k,1});
            ans += total + 1 - st.top().second;
            total++;
        }
        return ans;
    }
};