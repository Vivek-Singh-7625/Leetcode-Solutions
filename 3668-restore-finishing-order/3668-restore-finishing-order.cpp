class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        vector<bool> v(n, false);
        for(int i : friends)    v[i-1] = true;
        int k = 0;
        for(int i = 0; i < n; i++){
            if(v[order[i]-1]) friends[k++] = order[i];
        }
        return friends;
    }
};