class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = n-1 ; i >= -n ; i--){
            while(!st.empty() and nums[(n+i)%n] >= st.top()){
                st.pop();
            }
            if(!st.empty()) ans[(n+i)%n] = st.top();
            st.push(nums[(n+i)%n]);
        }
        return ans;
    }
};