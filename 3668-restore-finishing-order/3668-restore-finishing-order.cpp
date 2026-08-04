class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int> mpp;
        int k = 0;
        for(int i = 0 ; i < friends.size() ; i++)    mpp[friends[i]]++;
        for(int i = 0 ; i < order.size() ; i++){
            if(mpp[order[i]]--)    friends[k++] = order[i];
        }
        return  friends;
    }
};