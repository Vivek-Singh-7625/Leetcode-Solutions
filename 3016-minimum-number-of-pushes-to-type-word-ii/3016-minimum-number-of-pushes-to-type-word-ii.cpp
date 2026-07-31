class Solution {
public:
    int minimumPushes(string word) {
        vector<int> A(26,0);
        int n = word.size() , ans = 0;
        for(int i = 0 ; i < n ; i++)    A[word[i]-'a']++;
        sort(A.begin(),A.end(),greater<int>());
        for(int i = 0 ; i < 26 ; i++)   ans += (i/8 + 1)*A[i];
        return ans;
    }
};